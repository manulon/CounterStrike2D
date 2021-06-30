#include "FireArm.h"
#include "Player.h"
#include "World.h"

#define DENSITY 1.0f
#define FRICTION 0.0f
#define BODY_TYPE b2_dynamicBody

FireArm::FireArm(World &world,
				 float width, float height,
                 size_t maxAmmunition) : 
	Entity(world), loader(world, maxAmmunition), 
    width(width), height(height) { }

void FireArm::attachToWorld(float x, float y) {
    b2BodyDef bodyDef;
    b2PolygonShape polygonShape;
    b2FixtureDef fixtureDef;
    setBodyParams(bodyDef, x, y);
    setShapeParams(polygonShape, width, height, x, y);
    setFixtureParams(polygonShape, fixtureDef);
    Entity::attachToWorld(bodyDef, fixtureDef);
    /*xOrigin = x;
    yOrigin = y;
    this->x = x;
    this->y = y;*/
}

/*void FireArm::attachToPlayer(Player &player, float xOrigin, 
                             float yOrigin, float x, float y) {
    b2PolygonShape polygonShape;
    b2FixtureDef fixtureDef;
    setShapeParams(polygonShape, width, height, x + width, y);
    setFixtureParams(polygonShape, fixtureDef);
    player.bindFixture(fixtureDef);
    this->xOrigin = xOrigin;
    this->yOrigin = yOrigin;
    this->x = x + width;
    this->y = y;
}*/

/*FireArm::FireArm(FireArm &&other) : 
    Entity(std::move(other)), loader(std::move(other.loader)),
    width(other.width), height(other.height),
    x(other.x), y(other.y),
    xOrigin(other.xOrigin), yOrigin(other.yOrigin) { 
    other.width = 0;
    other.height = 0;
}*/

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
                             float width, float height,
                             float x, float y) {
    polygonShape.SetAsBox(width, height,b2Vec2(x, y), 0);	
}

void FireArm::setFixtureParams(const b2PolygonShape &polygonShape, 
						       b2FixtureDef &fixtureDef) {
    fixtureDef.shape = &polygonShape;
    fixtureDef.density = DENSITY;
    fixtureDef.friction = FRICTION;
}

void FireArm::shoot(float angle, float x, float y) {
    // TODO CORREGIR EXCEPCION DE EMPTY LOADER
    try {
        std::unique_ptr<Bullet> bullet(new Bullet(loader.releaseBullet()));
        //setBulletPosition(bullet, angle, x, y, width, height);
        bullet->shoot(angle, x, y);
        Entity::moveToWorld(std::move(bullet));
    } catch (...) { }
}

void FireArm::setBulletPosition(std::unique_ptr<Bullet> &bullet, float angle) {
    /*float radius = x + (width/2) + bullet->getRadius()*9.0f - xOrigin;
    bullet->attachToWorld(xOrigin + radius*cos(angle*b2_pi/180.0f), 
                          yOrigin + radius*sin(angle*b2_pi/180.0f));*/
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
