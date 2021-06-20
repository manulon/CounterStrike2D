#include "Bullet.h"
#include "World.h"

#define IMPULSE 1000.0f // NO IMPORTA SI AUMENTAMOS MAS HAY UN MAXIMO
#define RADIUS 0.1f
#define DENSITY 1.0f

Bullet::Bullet(World &world, float x, float y) : 
    body(nullptr) {
	b2BodyDef bodyDef;
    b2CircleShape circleShape;
    b2FixtureDef fixtureDef;
    setBodyParams(bodyDef, x, y);
    setCircleParams(circleShape);
    setFixtureParams(circleShape, fixtureDef);
    createBody(world, bodyDef);
    bindFixtureToBody(fixtureDef);
}

Bullet::Bullet(Bullet &&other) : body(other.body) { 
    other.body = nullptr;
}

Bullet::~Bullet() { }

void Bullet::setBodyParams(b2BodyDef &bodyDef, float x, float y) {
    bodyDef.type = b2_dynamicBody;
    bodyDef.bullet = true;
    bodyDef.position.Set(x, y);
}

void Bullet::createBody(World &world, b2BodyDef &bodyDef) {
    body = world.createBody(&bodyDef);
}

void Bullet::setCircleParams(b2CircleShape &circleShape) {
    circleShape.m_radius = RADIUS;
}

void Bullet::setFixtureParams(const b2CircleShape &circleShape, 
                              b2FixtureDef &fixtureDef) {
    fixtureDef.shape = &circleShape;
    fixtureDef.density = DENSITY;
}

void Bullet::bindFixtureToBody(const b2FixtureDef &fixtureDef) {
    body->CreateFixture(&fixtureDef);
}

void Bullet::shoot(float angle) {
    float radians = angleToRadians(angle);
    b2Vec2 position = body->GetPosition();
    b2Vec2 force(IMPULSE * cos(radians), IMPULSE * sin(radians));
    body->ApplyLinearImpulse(force, position, true); 
}

float Bullet::angleToRadians(float angle) {
	return (angle * b2_pi) / 180;
}

float Bullet::getPosition_x() const {
	return body->GetPosition().x;
}

float Bullet::getPosition_y() const {
    return body->GetPosition().y;
}

float Bullet::getAngle() const {
	return body->GetAngle();
}
