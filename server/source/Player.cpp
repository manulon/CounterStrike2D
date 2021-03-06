#include "Player.h"
#include "World.h"
#include "SWeapon.h"
#include "PrimaryWeapon.h"
#include "SecondaryWeapon.h"
#include "TertiaryWeapon.h"
#include "Knife.h"

#define DAMPING 70.0f //10.0f 
#define DENSITY 1.0f
#define MOVING_FORCE 200.0f
#define STOP_FORCE 0.0f
#define FIXED_ROTATION true
#define BODY_TYPE b2_dynamicBody

Player::Player(World &world, 
               float x, float y,
               float width, float height, short id) :
    Entity(world, id), force(0,0), life(), 
    currentWeapon(nullptr), width(width), height(height),
    pickingUpWeapon(false){ 
    setBodyParams(bodyDef, x, y);
    setShapeParams(polygonShape, width, height);
    setFixtureParams(polygonShape, fixtureDef);
    Entity::earlyAttachToWorld(bodyDef, fixtureDef);
    std::unique_ptr<Knife> knife(new Knife(0.1f, 0.1f));
    setTertiaryWeapon(std::move(knife));
}

Player::Player(Player &&other) : 
    Entity(std::move(other)),
    currentWeapon(other.currentWeapon),
    primaryWeapon(std::move(other.primaryWeapon)),
    secondaryWeapon(std::move(other.secondaryWeapon)),
    tertiaryWeapon(std::move(other.tertiaryWeapon)),
    width(other.width), height(other.height) {
    other.currentWeapon = nullptr;
    other.width = 0;
    other.height = 0;
}

void Player::setPrimaryWeapon(std::unique_ptr<PrimaryWeapon> &&other) {
    std::shared_ptr<SWeapon> weapon(new SWeapon(Entity::getWorld(), std::move(other)));
    primaryWeapon = std::move(weapon);
    setIfNullCurrentWeapon(primaryWeapon.get());
}

void Player::setSecondaryWeapon(std::unique_ptr<SecondaryWeapon> &&other) {
    std::shared_ptr<SWeapon> weapon(new SWeapon(Entity::getWorld(), std::move(other)));
    secondaryWeapon = std::move(weapon);
    setIfNullCurrentWeapon(secondaryWeapon.get());
}

void Player::setTertiaryWeapon(std::unique_ptr<TertiaryWeapon> &&other) {
    std::shared_ptr<SWeapon> weapon(new SWeapon(Entity::getWorld(), std::move(other)));
    tertiaryWeapon = std::move(weapon);
    setIfNullCurrentWeapon(tertiaryWeapon.get());
}

void Player::setIfNullCurrentWeapon(SWeapon *weapon) {
    if (currentWeapon == nullptr) {
        currentWeapon = weapon;
    }
}

Player::~Player() { }

void Player::setBodyParams(b2BodyDef &bodyDef, float x, float y) {
    bodyDef.userData = static_cast<void*>(this);
    bodyDef.type = BODY_TYPE;
    bodyDef.linearDamping = DAMPING;
    bodyDef.position.Set(x, y);  
}

void Player::setShapeParams(b2PolygonShape &polygonShape,
                            float width, float height) {
    polygonShape.SetAsBox(width, height);	
}

void Player::setFixtureParams(const b2PolygonShape &polygonShape, 
						      b2FixtureDef &fixtureDef) {
    fixtureDef.shape = &polygonShape;
    fixtureDef.density = DENSITY;
    fixtureDef.filter.categoryBits = PLAYER;
}

void Player::moveRight() {
    force.Set(MOVING_FORCE, force.y);
}

void Player::moveLeft() {
    force.Set(-MOVING_FORCE, force.y);
}

void Player::moveUp() {
    force.Set(force.x, -MOVING_FORCE);
}

void Player::moveDown() {
    force.Set(force.x, MOVING_FORCE); 
}

void Player::stopMoveRight() {
    force.Set(STOP_FORCE, force.y);
}

void Player::stopMoveLeft() {
    force.Set(STOP_FORCE, force.y);
}

void Player::stopMoveUp() {
    force.Set(force.x, STOP_FORCE);
}

void Player::stopMoveDown() {
    force.Set(force.x, STOP_FORCE); 
}

void Player::update() {
    Entity::applyForceToCenter(force, true);
}

void Player::attack(float angle) {
    Entity::setTransform(getPositionX(), getPositionY(), angle);
    float shootRadius = width;
    float xShoot = getPositionX() + shootRadius*cos(angle*b2_pi/180.0f);
    float yShoot = getPositionY() + shootRadius*sin(angle*b2_pi/180.0f);
    
    currentWeapon->attack(angle, xShoot, yShoot);
}

void Player::reload(size_t &ammunition) {
    currentWeapon->reload(ammunition);
}

void Player::collideWith(Entity &entity) {
    entity.collideWithPlayer(*this);
}

void Player::collideWithBullet(Bullet &bullet) {
    life.decreaseLife(bullet.getDamage());
    if (life.getLife() <= 0){
        this->detachFromWorld();
        dropPrimaryWeapon();
    }  
}

void Player::collideWithObstacle(Obstacle &obstacle) {
}

void Player::collideWithWeapon(SWeapon &other) {
}

void Player::collideWithPlayer(Player &player) {
}

void Player::collideWithBorder(Border &border) {
}

void Player::swapAndDropPrimaryWeapon(PrimaryWeapon &other) {
    bool isCurrentWeapon = false;
    if (currentWeapon == primaryWeapon.get()) isCurrentWeapon = true;
    dropPrimaryWeapon();
    setPrimaryWeapon(other);
    if (isCurrentWeapon) currentWeapon = primaryWeapon.get();
}

void Player::swapAndDropSecondaryWeapon(SecondaryWeapon &other) {
    bool isCurrentWeapon = false;
    if (currentWeapon == secondaryWeapon.get()) isCurrentWeapon = true;
    dropSecondaryWeapon();
    setSecondaryWeapon(other);
    if (isCurrentWeapon) currentWeapon = secondaryWeapon.get();
}

void Player::setBody(b2Body &body) {
    Entity::setBody(body);
    Entity::bindFixture(fixtureDef);
}

void Player::decreaseLife(int valueToDecrease){
    life.decreaseLife(valueToDecrease);
}

void Player::dropPrimaryWeapon(){
    if (primaryWeapon.get() != nullptr){
        primaryWeapon->lateAttachToWorld(getPositionX()+1, getPositionY());
        primaryWeapon->setId(15);
        Entity::getWorld().spawnWeapon(std::move(primaryWeapon));
    }
}

void Player::setPrimaryWeapon(PrimaryWeapon &other) {
    SWeapon *otherWeapon = other.getContext();
    primaryWeapon = std::move(Entity::getWorld().retrieveSpawnedWeapon(*otherWeapon));
    primaryWeapon->detachFromWorld();
}

void Player::dropSecondaryWeapon() {
    if (secondaryWeapon.get() != nullptr){
        secondaryWeapon->lateAttachToWorld(getPositionX()+1, getPositionY());
        Entity::getWorld().spawnWeapon(std::move(secondaryWeapon));
    }
}

void Player::setSecondaryWeapon(SecondaryWeapon &other) {
    SWeapon *otherWeapon = other.getContext();
    secondaryWeapon = std::move(Entity::getWorld().retrieveSpawnedWeapon(*otherWeapon));
    secondaryWeapon->detachFromWorld();
}

short Player::getLife(){
    return (short)life.getLife();
}

void Player::pickUpWeapon(){
    pickingUpWeapon = true;
}

void Player::stopPickingUpWeapon(){
    pickingUpWeapon = false;
}

bool Player::isPickingUpWeapon(){
    return pickingUpWeapon;
}

bool Player::isDead() {
    return life.getLife() == 0 ? true : false;
}

void Player::setAngle(short newAngle){
    angle = newAngle;
}

short Player::getAngle(){
    return angle;
}

void Player::switchWeapon(char weapon){
    if (weapon == 1) {
        currentWeapon = primaryWeapon.get();
    } else if (weapon == 2) {
        currentWeapon = tertiaryWeapon.get();
    } 
    // else if (weapon == 3) {
    //     currentWeapon = tertiaryWeapon.get();
    // }
}

short Player::getCurrentWeapon(){
    return currentWeapon->getId();
}
