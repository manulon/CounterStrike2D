#include "Bullet.h"

#define IMPULSE 1000.0f // NO IMPORTA SI AUMENTAMOS MAS HAY UN MAXIMO
#define RADIUS 0.1f
#define RESTITUTION 0.0f
#define DENSITY 1.0f
#define IS_BULLET true
#define BODY_TYPE b2_dynamicBody

Bullet::Bullet(World &world, float x, float y) : 
    Entity(EntityID::BULLET) {
	b2BodyDef bodyDef;
    b2CircleShape circleShape;
    b2FixtureDef fixtureDef;
    setBodyParams(bodyDef, x, y);
    setShapeParams(circleShape);
    setFixtureParams(circleShape, fixtureDef);

    createEntity(world, bodyDef, fixtureDef);
}

Bullet::Bullet(Bullet &&other) : Entity(std::move(other)) { }

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

void Bullet::shoot(float angle) {
    float radians = angleToRadians(angle);
    b2Vec2 force(IMPULSE * cos(radians), IMPULSE * sin(radians));
    applyLinearImpulseToCenter(force, true);
}

float Bullet::angleToRadians(float angle) {
	return (angle * b2_pi) / 180;
}
