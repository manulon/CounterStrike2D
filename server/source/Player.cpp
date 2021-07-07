#include "Player.h"
#include "World.h"
#include "SWeapon.h"
#include "PrimaryWeapon.h"
#include "TertiaryWeapon.h"

#define DAMPING 10.0f
#define DENSITY 1.0f
#define FRICTION 0.0f
#define MOVING_FORCE 250.0f
#define STOP_FORCE 0.0f
#define FIXED_ROTATION true
#define BODY_TYPE b2_dynamicBody

Player::Player(World &world, 
               float x, float y,
               float width, float height, short id) :
    Entity(world, id), force(0,0),
    life(),width(width), height(height) { 
    setBodyParams(bodyDef, x, y);
    setShapeParams(polygonShape, width, height);
    setFixtureParams(polygonShape, fixtureDef);
    Entity::earlyAttachToWorld(bodyDef, fixtureDef);
}

Player::Player(Player &&other) : 
    Entity(std::move(other)),
    currentWeapon(other.currentWeapon),
    primaryWeapon(std::move(other.primaryWeapon)), //implementar constructor movimiento weapon
    width(other.width), height(other.height) {
    currentWeapon = nullptr;
    other.width = 0;
    other.height = 0;
}

void Player::setPrimaryWeapon(std::unique_ptr<PrimaryWeapon> &&other) {
    std::unique_ptr<SWeapon> weapon(new SWeapon(Entity::getWorld(), std::move(other)));
    primaryWeapon = std::move(weapon);
    setCurrentWeapon(primaryWeapon.get());
}

void Player::setTertiaryWeapon(std::unique_ptr<TertiaryWeapon> &&other) {
    std::unique_ptr<SWeapon> weapon(new SWeapon(Entity::getWorld(), std::move(other)));
    tertiaryWeapon = std::move(weapon);
    setCurrentWeapon(tertiaryWeapon.get());
}

void Player::setCurrentWeapon(SWeapon *weapon) {
    if (weapon != nullptr) {
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
    fixtureDef.friction = FRICTION;
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
    std::cout << "player chocado por bala\n";
    life.decreaseLife(bullet.getDamage());
}

void Player::collideWithObstacle(Obstacle &obstacle) {
    std::cout << "player chocado por obstaculo\n";
}

void Player::collideWithWeapon(SWeapon &other) {
    std::cout << "player chocado por SWeapon\n";
}

void Player::collideWithPlayer(Player &player) {
    std::cout << "player chocado por player\n";
}

void Player::collideWithBorder(Border &border) {
    std::cout << "Player chocado por border\n";
}

void Player::swapAndDropPrimaryWeapon(PrimaryWeapon &other) {
    std::cout << "player chocado por primaryWeapon\n";
    // SI LOS MUNDOS EN QUE VIVEN LAS ARMAS SON DIFERENTES FALLARA
    // SI NO EXISTE EL ARMA EN EL MUNDO 
    primaryWeapon->lateAttachToWorld(getPositionX()+5, getPositionY());
    Entity::getWorld().spawnWeapon(std::move(primaryWeapon));
    SWeapon *otherWeapon = other.getContext();
    primaryWeapon = std::move(Entity::getWorld().retrieveSpawnedWeapon(*otherWeapon));
    primaryWeapon->detachFromWorld();
    //currentWeapon = primaryWeapon.get();
}

void Player::swapAndDropTertiaryWeapon(TertiaryWeapon &other) {
    std::cout << "player chocado por TertiaryWeapon\n";
    // SI HICIERA FALTA AGREGAR CODIGO DE RESPUESTA
}

void Player::setBody(b2Body &body) {
    Entity::setBody(body);
    Entity::bindFixture(fixtureDef);
}

void Player::decreaseLife(int valueToDecrease){
    life.decreaseLife(valueToDecrease);
}