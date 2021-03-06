#include "Border.h"
#include "Bullet.h"
#define DENSITY 1.0f
#define DELTA 0.1f

Border::Border(World &world,
               float x, float y,
               float width, float height) : 
    Entity(world, 150), x(x), y(y),
    width(width), height(height) {
    setBodyParams(borderDef, x, y);
    setFixtureParams(side, fixtureDef);
    
    side.SetAsBox(width, DELTA, b2Vec2(x, y - height/2), 0);
    Entity::earlyAttachToWorld(borderDef, fixtureDef);
    side.SetAsBox(DELTA, height, b2Vec2(x + width/2, y), 0);
    Entity::bindFixture(fixtureDef);
    side.SetAsBox(width, DELTA, b2Vec2(x, y + height/2 ), 0);
    Entity::bindFixture(fixtureDef);
    side.SetAsBox(DELTA, height, b2Vec2(x - width/2-0.1f, y), 0);
    Entity::bindFixture(fixtureDef);

}

Border::Border(Border &&other) : 
    Entity(std::move(other)) { }

Border::~Border() { }

void Border::setBodyParams(b2BodyDef &bodyDef, float x, float y) {
    bodyDef.userData = static_cast<void*>(this);
	bodyDef.position.Set(x, y);
}

void Border::setFixtureParams(const b2PolygonShape &polygonShape, 
                              b2FixtureDef &fixtureDef) {
    fixtureDef.shape = &polygonShape;
    fixtureDef.density = DENSITY;
    fixtureDef.friction = 1.0f;
    fixtureDef.filter.categoryBits = BORDER;
}

void Border::collideWith(Entity &entity) {
    entity.collideWithBorder(*this);
}

void Border::collideWithBullet(Bullet &bullet) {
}

void Border::collideWithObstacle(Obstacle &obstacle) {
}

void Border::collideWithWeapon(SWeapon &weapon) {
}

void Border::collideWithPlayer(Player &player) {
}

void Border::collideWithBorder(Border &border) {
}

void Border::setBody(b2Body &body) {
    Entity::setBody(body);
    side.SetAsBox(width, DELTA, b2Vec2(x, y - height/2), 0);
    Entity::bindFixture(fixtureDef);
    side.SetAsBox(width, DELTA, b2Vec2(x, y - height/2), 0);
    Entity::bindFixture(fixtureDef);
    side.SetAsBox(DELTA, height, b2Vec2(x + width/2, y), 0);
    Entity::bindFixture(fixtureDef);
    side.SetAsBox(width, DELTA, b2Vec2(x, y + height/2 ), 0);
    Entity::bindFixture(fixtureDef);
}
