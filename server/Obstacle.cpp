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

void Obstacle::collidingWithBullet(Entity &other){
    std::cout<<"obstaculo chocado por bala\n";
}
void Obstacle::collidingWithPlayer(Entity &other){
    std::cout<<"Obstacle chocado por player\n";
}
void Obstacle::collidingWithFireArm(Entity &other){
    std::cout<<"Obstacle chocado por firearm\n";
}
void Obstacle::collidingWithObstacle(Entity &other){
    std::cout<<"Obstacle chocado por obstavulo\n";
}

void Obstacle::collideWith(Entity &other){
    other.collidingWithObstacle(*this);
}