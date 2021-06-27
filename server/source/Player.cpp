#include "Player.h"

#define DAMPING 10.0f
#define DENSITY 1.0f
#define FRICTION 0.0f
#define MOVING_FORCE 100.0f
#define STOP_FORCE 0.0f
#define FIXED_ROTATION true
#define BODY_TYPE b2_dynamicBody

Player::Player(World &world, 
               float x, float y,
               float width, float height) :
    Entity(world), force(0,0) { 
    b2BodyDef bodyDef;
    b2PolygonShape polygonShape;
    b2FixtureDef fixtureDef;
    setBodyParams(bodyDef, x, y);
    setShapeParams(polygonShape, width, height);
    setFixtureParams(polygonShape, fixtureDef);
    Entity::init(bodyDef, fixtureDef);
}

Player::Player(Player &&other) : Entity(std::move(other)) { }

Player::~Player() { }

void Player::setBodyParams(b2BodyDef &bodyDef, float x, float y) {
    bodyDef.userData = static_cast<void*>(this);
    bodyDef.type = BODY_TYPE;
    bodyDef.linearDamping = DAMPING;
    // OJO NO SE SI ESTE FIXED ROTATION AFECTE EL MOVIMIENTO DEL CUERPO
    bodyDef.fixedRotation = FIXED_ROTATION;
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

void Player::collideWith(Entity &entity) {
    entity.collideWithPlayer(*this);
}

void Player::collideWithBullet(Bullet &bullet) {
    std::cout << "player chocado por bala\n";
}

void Player::collideWithObstacle(Obstacle &obstacle) {
    std::cout << "player chocado por obstaculo\n";
}

void Player::collideWithFireArm(FireArm &fireArm) {
    std::cout << "player chocado por firearm\n";
}

void Player::collideWithPlayer(Player &player) {
    std::cout << "player chocado por player\n";
}

void Player::collideWithBorder(Border &border) {
    std::cout << "Player chocado por border\n";
}
