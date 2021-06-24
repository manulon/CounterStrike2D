#include "Obstacle.h"

#define DENSITY 1.0f

Obstacle::Obstacle(World &world, 
				   float x, float y,
				   float width, float height) : 
    Entity(EntityID::OBSTACLE) {
    b2BodyDef bodyDef;
    b2PolygonShape polygonShape;
    setBodyParams(bodyDef, x, y);
    setShapeParams(polygonShape, width, height);

    createEntity(world, bodyDef, polygonShape, DENSITY);
}

Obstacle::Obstacle(Obstacle &&other) : Entity(std::move(other)) { }

Obstacle::~Obstacle() { }

void Obstacle::setBodyParams(b2BodyDef &bodyDef, float x, float y) {
    bodyDef.userData = static_cast<void*>(this);
	bodyDef.position.Set(x, y);
}

void Obstacle::setShapeParams(b2PolygonShape &polygonShape,
                      		  float width, float height) {
    polygonShape.SetAsBox(width, height);	
}
