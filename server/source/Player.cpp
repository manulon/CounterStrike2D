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
    width(width), height(height) { 
    setBodyParams(bodyDef, x, y);
    setShapeParams(polygonShape, width, height);
    setFixtureParams(polygonShape, fixtureDef);
    Entity::earlyAttachToWorld(bodyDef, fixtureDef);
}

Player::Player(Player &&other) : 
    Entity(std::move(other)), 
    weapon(std::move(other.weapon)), //implementar constructor movimiento weapon
    width(other.width), height(other.height) {
    other.width = 0;
    other.height = 0;
}

void Player::setWeapon(std::unique_ptr<SWeapon> &&other) {
    weapon = std::move(other);
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
    weapon->attack(angle, xShoot, yShoot);
}

void Player::reload(size_t &ammunition) {
    weapon->reload(ammunition);
}

void Player::collideWith(Entity &entity) {
    entity.collideWithPlayer(*this);
}

void Player::collideWithBullet(Bullet &bullet) {
    std::cout << "player chocado por bala\n";
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

void Player::collideWithPrimaryWeapon(PrimaryWeapon &other) {
    std::cout << "player chocado por primaryWeapon\n";
    // SI LOS MUNDOS EN QUE VIVEN LAS ARMAS SON DIFERENTES FALLARA
    // SI NO EXISTE EL ARMA EN EL MUNDO 
    weapon->lateAttachToWorld(getPositionX()+5, getPositionY());
    Entity::getWorld().spawnWeapon(std::move(weapon));
    SWeapon *otherWeapon = other.getContext();
    weapon = std::move(Entity::getWorld().retrieveSpawnedWeapon(*otherWeapon));
    weapon->detachFromWorld();
}

void Player::collideWithTertiaryWeapon(TertiaryWeapon &other) {
    std::cout << "player chocado por TertiaryWeapon\n";
    // SI HICIERA FALTA AGREGAR CODIGO DE RESPUESTA
}

void Player::setBody(b2Body &body) {
    Entity::setBody(body);
    Entity::bindFixture(fixtureDef);
}
