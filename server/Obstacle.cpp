#include "Obstacle.h"
#include "World.h"

Obstacle::Obstacle(World &world, 
				   float x, float y,
				   float width, float height) {
    b2BodyDef bodyDef;
    b2PolygonShape polygonShape;
    setBodyParams(bodyDef, x, y);
    setShapeParams(polygonShape, width, height);
    createBody(world, bodyDef);
    bindFixtureToBody(polygonShape);
}

Obstacle::Obstacle(Obstacle &&other) : body(other.body) {
    other.body = nullptr;
}

Obstacle::~Obstacle() { }

void Obstacle::setBodyParams(b2BodyDef &bodyDef, float x, float y) {
	bodyDef.position.Set(x, y);
}

void Obstacle::createBody(World &world, b2BodyDef &bodyDef) {
    body = world.createBody(&bodyDef);
}

void Obstacle::setShapeParams(b2PolygonShape &polygonShape,
                      		  float width, float height) {
    polygonShape.SetAsBox(width, height);	
}

void Obstacle::bindFixtureToBody(const b2PolygonShape &polygonShape) {
    body->CreateFixture(&polygonShape, 0.0f);
}

float Obstacle::getPosition_x() const {
	return body->GetPosition().x;
}

float Obstacle::getPosition_y() const {
    return body->GetPosition().y;
}

float Obstacle::getAngle() const {
	return body->GetAngle();
}
