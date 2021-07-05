#include "Knife.h"
#include <iostream>
#include <cmath>

#define DENSITY 0.1f
#define WIDTH 0.2f //Dimensiones del cuchillo
#define HEIGHT 0.1f //

Knife::Knife(World &world) : 
	Entity(world,21) { 
}

Knife::Knife(Knife &&other) : 
	Entity(std::move(other)) {
}

Knife::~Knife() { }

void Knife::setBodyParams(b2BodyDef &bodyDef, float x, float y) {
    bodyDef.userData = static_cast<void*>(this);
    bodyDef.position.Set(x, y); 
}

void Knife::setShapeParams(b2PolygonShape &polygonShape) {
    polygonShape.SetAsBox(WIDTH, HEIGHT);	
}

void Knife::setFixtureParams(const b2PolygonShape &polygonShape, 
						      b2FixtureDef &fixtureDef) {
    fixtureDef.shape = &polygonShape;
    fixtureDef.density = DENSITY;
}

void Knife::earlyAttachToWorld(float x, float y) {
    setBodyParams(bodyDef, x, y);
    setShapeParams(polygonShape);
    setFixtureParams(polygonShape, fixtureDef);
    Entity::attachToWorld(bodyDef, fixtureDef);
}

void Knife::attack(float angle, float x, float y) {
    float radians = angleToRadians(angle);
    float radius = sqrt(pow(WIDTH, 2) + pow(HEIGHT, 2));
    earlyAttachToWorld(x + radius*cos(radians)*2, 
          	           y + radius*sin(radians)*2);
    Entity::detachFromWorld();
}

float Knife::angleToRadians(float angle) {
	return (angle * b2_pi) / 180;
}

void Knife::collideWith(Entity &entity) { 
    entity.collideWithKnife(*this);
}

void Knife::collideWithBullet(Bullet &bullet) {
	std::cout << "Knife chocado por bullet" << std::endl;
}

void Knife::collideWithObstacle(Obstacle &obstacle) { 
	std::cout << "Knife chocado por obstacle" << std::endl;
}

void Knife::collideWithFireArm(FireArm &fireArm) { 
	std::cout << "Knife chocado por firearm" << std::endl;
}

void Knife::collideWithPlayer(Player &player) { 
	std::cout << "Knife chocado por player" << std::endl;
}

void Knife::collideWithBorder(Border &border) { 
	std::cout << "Knife chocado por border" << std::endl;
}

void Knife::collideWithKnife(Knife &knife) {
	std::cout << "Knife chocado por knife" << std::endl;
}

void Knife::setBody(b2Body &body) {
    Entity::setBody(body);
    Entity::bindFixture(fixtureDef);
}
