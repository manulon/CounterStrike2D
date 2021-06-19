#include "Player.h"
#include "World.h"
#include <Box2D/Box2D.h>

#define PLAYER_WIDTH 1.0f
#define PLAYER_HEIGHT 1.0f
#define PLAYER_DAMPING 10.0f
#define PLAYER_DENSITY 1.0f
#define PLAYER_FRICTION 0.0f
#define PLAYER_MOVING_FORCE 100.0f

Player::Player(World &world, 
               float x, float y,
               float width, float height) { 
	initBody(world, x, y, width, height);
}

Player::~Player() { }

void Player::initBody(World &world, 
                      float x, float y,
                      float width, float height) {
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.linearDamping = PLAYER_DAMPING;
    bodyDef.position.Set(x, y);
    body = world.createBody(&bodyDef);

    b2PolygonShape polygonShape;
    setShape(polygonShape, width, height);

    b2FixtureDef fixtureDef;
    setFixture(polygonShape, fixtureDef);

    body->CreateFixture(&fixtureDef);
}

void Player::setShape(b2PolygonShape &polygonShape,
                      float width, float height) {
    polygonShape.SetAsBox(width, height);	
}

void Player::setFixture(const b2PolygonShape &polygonShape, 
						b2FixtureDef &fixtureDef) {
    fixtureDef.shape = &polygonShape;
    fixtureDef.density = PLAYER_DENSITY;
    fixtureDef.friction = PLAYER_FRICTION;
}

float Player::getPosition_x() const {
	return body->GetPosition().x;
}

float Player::getPosition_y() const {
    return body->GetPosition().y;
}

float Player::getAngle() const {
	return body->GetAngle();
}

void Player::moveRight() {
    b2Vec2 force(100, 0);
    body->ApplyForceToCenter(force, false); 
}
