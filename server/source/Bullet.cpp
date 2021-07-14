#include "Bullet.h"

#define IMPULSE 1.0f
#define RADIUS 0.1f
#define RESTITUTION 0.0f
#define DENSITY 0.1f
#define IS_BULLET true
#define BODY_TYPE b2_dynamicBody

Bullet::Bullet(World &world) : 
    Entity(world, 60), damage() {
}

void Bullet::attachToWorld(float x, float y) {
    setBodyParams(bodyDef, x, y);
    setShapeParams(circleShape);
    setFixtureParams(circleShape, fixtureDef);
    Entity::earlyAttachToWorld(bodyDef, fixtureDef);
}

Bullet::Bullet(Bullet &&other) : 
    Entity(std::move(other)), damage(){}

Bullet::~Bullet() { }

void Bullet::setBodyParams(b2BodyDef &bodyDef, float x, float y) {
    bodyDef.userData = static_cast<void*>(this);
    bodyDef.type = BODY_TYPE;
    bodyDef.bullet = IS_BULLET;
    bodyDef.position.Set(x, y);
}

void Bullet::setShapeParams(b2CircleShape &circleShape) {
    circleShape.m_radius = RADIUS;
}

void Bullet::setFixtureParams(const b2CircleShape &circleShape, 
                              b2FixtureDef &fixtureDef) {
    fixtureDef.shape = &circleShape;
    fixtureDef.restitution = RESTITUTION;
    fixtureDef.density = DENSITY;
    fixtureDef.filter.categoryBits = BULLET;
    fixtureDef.filter.maskBits = PLAYER | OBSTACLE | BORDER;
}

void Bullet::shoot(float angle, float x, float y) {
    float radians = angleToRadians(angle);
    attachToWorld(x + RADIUS*cos(radians)*2, 
                  y + RADIUS*sin(radians)*2);
    b2Vec2 force(IMPULSE * cos(radians), IMPULSE * sin(radians));
    Entity::applyLinearImpulseToCenter(force, true);
}

float Bullet::angleToRadians(float angle) {
	return (angle * b2_pi) / 180;
}

void Bullet::collideWith(Entity &entity) {
    entity.collideWithBullet(*this);
}

void Bullet::collideWithBullet(Bullet &bullet) {
    std::cout << "bullet chocado por bala\n";
}

void Bullet::collideWithObstacle(Obstacle &obstacle) {
    std::cout << "bullet chocado por obstaculo y destruido\n";
    Entity::detachFromWorld();
}

void Bullet::collideWithWeapon(SWeapon &weapon) {
    std::cout << "bullet chocado por weapon\n";
}

void Bullet::collideWithPlayer(Player &player) {
    std::cout << "bullet chocado por player\n";
    Entity::detachFromWorld();
}

void Bullet::collideWithBorder(Border &border) {
    std::cout << "Bullet chocado por border\n";
    std::cout <<"x: "<<getPositionX()<<" y: "<<getPositionY()<<std::endl;
    Entity::detachFromWorld();
}

/*std::ostream& operator<<(std::ostream &os, const Bullet &obj) {
    os << "bullet";
    return os;
}*/

float Bullet::getRadius() {
    return RADIUS;
}

void Bullet::setBody(b2Body &body) {
    Entity::setBody(body);
    Entity::bindFixture(fixtureDef);
}

int Bullet::getDamage(){
    return damage.getDamage();
}

void Bullet::setDamage(int value){
    damage.setDamage(value);
}