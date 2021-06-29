#include "FireArm.h"

#define DENSITY 1.0f
#define FRICTION 0.0f
#define BODY_TYPE b2_dynamicBody

FireArm::FireArm(World &world,
				 float x, float y,
				 float width, float height,
                 size_t maxAmmunition) : 
	Entity(world), loader(world, maxAmmunition), 
    width(width), height(height) { 
    b2BodyDef bodyDef;
    b2PolygonShape polygonShape;
    b2FixtureDef fixtureDef;
    setBodyParams(bodyDef, x, y);
    setShapeParams(polygonShape, width, height);
    setFixtureParams(polygonShape, fixtureDef);
    Entity::attachToWorld(bodyDef, fixtureDef);
}

FireArm::FireArm(FireArm &&other) : 
    Entity(std::move(other)), loader(std::move(other.loader)),
    width(other.width), height(other.height) { 
    other.width = 0;
    other.height = 0;
}

FireArm::~FireArm() { }

void FireArm::setBodyParams(b2BodyDef &bodyDef, float x, float y) {
    bodyDef.userData = static_cast<void*>(this);
    bodyDef.position.Set(x, y);  
}

void FireArm::setShapeParams(b2PolygonShape &polygonShape,
                             float width, float height) {
    polygonShape.SetAsBox(width, height);	
}

void FireArm::setFixtureParams(const b2PolygonShape &polygonShape, 
						       b2FixtureDef &fixtureDef) {
    fixtureDef.shape = &polygonShape;
    fixtureDef.density = DENSITY;
    fixtureDef.friction = FRICTION;
}

void FireArm::shoot(float angle) {
    // TODO CORREGIR EXCEPCION DE EMPTY LOADER
    try {
        std::unique_ptr<Bullet> bullet(new Bullet(loader.releaseBullet()));
        setBulletPosition(bullet);
        bullet->shoot(angle);
        Entity::moveToWorld(std::move(bullet));
    } catch (...) { }
}

void FireArm::setBulletPosition(std::unique_ptr<Bullet> &bullet) {
    float radius = bullet->getRadius();
    bullet->attachToWorld(getPositionX() + width/2.0f + radius*2.0f,
                          getPositionY() + height/2.0f + radius*2.0f);   
}

void FireArm::reload(size_t &ammunition) {
	loader.reload(ammunition);
}

void FireArm::collideWith(Entity &entity) {
    entity.collideWithFireArm(*this);
}

void FireArm::collideWithBullet(Bullet &bullet) {
    std::cout << "obstacle chocado por bala\n";
}

void FireArm::collideWithObstacle(Obstacle &obstacle) {
    std::cout << "obstacle chocado por obstaculo\n";
}

void FireArm::collideWithFireArm(FireArm &fireArm) {
    std::cout << "obstacle chocado por firearm\n";
}

void FireArm::collideWithPlayer(Player &player) {
    std::cout << "obstacle chocado por player\n";
}

void FireArm::collideWithBorder(Border &border) {
    std::cout << "FireArm chocado por border\n";
}
