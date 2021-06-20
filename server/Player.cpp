#include "Player.h"
#include "World.h"
#include <iostream>

#define DAMPING 10.0f
#define DENSITY 1.0f
#define FRICTION 0.0f
#define PLAYER_MOVING_FORCE 100.0f

Player::Player(World &world, 
               float x, float y,
               float width, float height) :
    body(nullptr), force(0,0) { 
    b2BodyDef bodyDef;
    b2PolygonShape polygonShape;
    b2FixtureDef fixtureDef;
    setBodyParams(bodyDef, x, y);
    setShapeParams(polygonShape, width, height);
    setFixtureParams(polygonShape, fixtureDef);
    createBody(world, bodyDef);
    bindFixtureToBody(fixtureDef);
}

Player::Player(Player &&other) : body(other.body) {
    other.body = nullptr;
}

Player::~Player() { }

void Player::setBodyParams(b2BodyDef &bodyDef, float x, float y) {
    bodyDef.type = b2_dynamicBody;
    bodyDef.linearDamping = DAMPING;
    bodyDef.position.Set(x, y);  
}

void Player::createBody(World &world, b2BodyDef &bodyDef) {
    body = world.createBody(&bodyDef);   
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

void Player::bindFixtureToBody(const b2FixtureDef &fixtureDef) {
    body->CreateFixture(&fixtureDef);
}

float Player::getPosition_x() const {
	return body->GetPosition().x;
}

float Player::getPosition_y() const {
    return body->GetPosition().y;
}

float Player::getAngle() const {
    b2Vec2 vel = body->GetLinearVelocity();
    double angle = (atan(vel.x / vel.y) * 180) / b2_pi;
    if (!isnan(angle)){
        body->SetTransform(body->GetPosition(),angle);        
    }
    return body->GetAngle();
}

void Player::moveRight() {
    // b2Vec2 force(100, 0);
    // body->ApplyForceToCenter(force, true); 
    force.Set(100, force.y);
}

void Player::moveLeft() {
    // b2Vec2 force(-100, 0);
    // body->ApplyForceToCenter(force, true); 
    force.Set(-100, force.y);
}

void Player::moveUp() {
    // b2Vec2 force(0, -100);
    // body->ApplyForceToCenter(force, true); 
    force.Set(force.x, -100);
}

void Player::moveDown() {
    // b2Vec2 force(0, 100);
    // body->ApplyForceToCenter(force, true);
    force.Set(force.x, 100); 
}
void Player::stopMoveRight() {
    // b2Vec2 force(100, 0);
    // body->ApplyForceToCenter(force, true); 
    force.Set(0, force.y);
}

void Player::stopMoveLeft() {
    // b2Vec2 force(-100, 0);
    // body->ApplyForceToCenter(force, true); 
    force.Set(0, force.y);
}

void Player::stopMoveUp() {
    // b2Vec2 force(0, -100);
    // body->ApplyForceToCenter(force, true); 
    force.Set(force.x, 0);
}

void Player::stopMoveDown() {
    // b2Vec2 force(0, 100);
    // body->ApplyForceToCenter(force, true);
    force.Set(force.x, 0); 
}

void Player::update() {
    std::cout<<"FUERZA X: "<<force.x<<"FUERZA Y: "<<force.y<<std::endl;
    body->ApplyForceToCenter(force,true);
}
