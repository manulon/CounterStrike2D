#include "Bullet.h"

#define IMPULSE 1000.0f // NO IMPORTA SI AUMENTAMOS MAS HAY UN MAXIMO
#define RADIUS 0.1f
#define RESTITUTION 0.0f
#define DENSITY 0.1f
#define IS_BULLET true
#define BODY_TYPE b2_dynamicBody

Bullet::Bullet(World &world) : 
    Entity(world, 60) {
}

void Bullet::attachToWorld(float x, float y) {
    setBodyParams(bodyDef, x, y);
    setShapeParams(circleShape);
    setFixtureParams(circleShape, fixtureDef);
    Entity::earlyAttachToWorld(bodyDef, fixtureDef);
}

Bullet::Bullet(Bullet &&other) : 
    Entity(std::move(other)) { }

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

void Bullet::collideWithFireArm(FireArm &fireArm) {
    std::cout << "bullet chocado por firearm\n";
}

void Bullet::collideWithPlayer(Player &player) {
    std::cout << "bullet chocado por player\n";
}

void Bullet::collideWithBorder(Border &border) {
    std::cout << "Bullet chocado por border\n";
    std::cout <<"x: "<<getPositionX()<<" y: "<<getPositionY()<<std::endl;
    Entity::detachFromWorld();
}

void Bullet::collideWithKnife(Knife &knife) {
    std::cout << "Bullet chocado por knife" << std::endl;
}

/*std::ostream& operator<<(std::ostream &os, const Bullet &obj) {
    os << "bullet";
    return os;
}*/

float Bullet::getRadius() {
    return RADIUS;
}

/*Bullet& Bullet::clone(const Bullet &other) {
    if (this == &other) return *this;
    Entity::clone(other);
    // TODO: SI ALGO FALLA PUEDE QUE SE NECESITE
    // AÑADIR AL MUNDO UN NUEVO BODY CON
    //if (!Entity::isDetached()) { 
    //    attachToWorld(getPositionX(), getPositionY()); 
    //}
    bodyDef = other.bodyDef;
    circleShape = other.circleShape;
    fixtureDef = other.fixtureDef;
    return *this;
}*/

void Bullet::setBody(b2Body &body) {
    Entity::setBody(body);
    Entity::bindFixture(fixtureDef);
}
