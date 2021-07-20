#include "Obstacle.h"
#include "Bullet.h"

#define DENSITY 1.0f

Obstacle::Obstacle(World &world, 
				   float x, float y,
				   float width, float height) : 
    Entity(world,-1) {
    setBodyParams(bodyDef, x, y);
    setShapeParams(polygonShape, width, height);
    setFixtureParams(polygonShape, fixtureDef);
    Entity::earlyAttachToWorld(bodyDef, fixtureDef);
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

void Obstacle::setFixtureParams(const b2PolygonShape &polygonShape, 
                              b2FixtureDef &fixtureDef) {
    fixtureDef.shape = &polygonShape;
    fixtureDef.density = DENSITY;
    fixtureDef.filter.categoryBits = OBSTACLE;
}

void Obstacle::collideWith(Entity &entity) {
    entity.collideWithObstacle(*this);
}

void Obstacle::collideWithBullet(Bullet &bullet) {
}

void Obstacle::collideWithObstacle(Obstacle &obstacle) {
}

void Obstacle::collideWithWeapon(SWeapon &weapon) {
}

void Obstacle::collideWithPlayer(Player &player) {
}

void Obstacle::collideWithBorder(Border &border) {
}

void Obstacle::setBody(b2Body &body) {
    Entity::setBody(body);
    Entity::bindFixture(fixtureDef);
}
