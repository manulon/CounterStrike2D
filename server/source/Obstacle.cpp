#include "Obstacle.h"
#include "Bullet.h"

#define DENSITY 1.0f

Obstacle::Obstacle(World &world, 
				   float x, float y,
				   float width, float height) : 
    Entity(world,1) {
    b2BodyDef bodyDef;
    setBodyParams(bodyDef, x, y);
    setShapeParams(polygonShape, width, height);
    Entity::attachToWorld(bodyDef, polygonShape, DENSITY);
}

Obstacle::Obstacle(Obstacle &&other) : 
    Entity(std::move(other)) { }

Obstacle::~Obstacle() { }

void Obstacle::setBodyParams(b2BodyDef &bodyDef, float x, float y) {
    bodyDef.userData = static_cast<void*>(this);
	bodyDef.position.Set(x, y);
}

void Obstacle::setShapeParams(b2PolygonShape &polygonShape,
                      		  float width, float height) {
    polygonShape.SetAsBox(width, height);	
}

void Obstacle::collideWith(Entity &entity) {
    entity.collideWithObstacle(*this);
}

void Obstacle::collideWithBullet(Bullet &bullet) {
    std::cout << "obstacle chocado por bala\n";
}

void Obstacle::collideWithObstacle(Obstacle &obstacle) {
    std::cout << "obstacle chocado por obstaculo\n";
}

void Obstacle::collideWithFireArm(FireArm &fireArm) {
    std::cout << "obstacle chocado por firearm\n";
}

void Obstacle::collideWithPlayer(Player &player) {
    std::cout << "obstacle chocado por jugador\n";
}

void Obstacle::collideWithBorder(Border &border) {
    std::cout << "Obstacle chocado por border\n";
}

void Obstacle::collideWithKnife(Knife &knife) {
    std::cout << "Obstacle chocado por knife" << std::endl;
}

void Obstacle::setBody(b2Body &body) {
    Entity::setBody(body);
    Entity::bindFixture(polygonShape, DENSITY);
}
