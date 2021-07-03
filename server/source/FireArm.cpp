#include "FireArm.h"
#include "Player.h"
#include "World.h"

#define DENSITY 1.0f
#define FRICTION 0.0f

FireArm::FireArm(World &world,
				 float width, float height,
                 size_t maxAmmunition) : 
	Entity(world), loader(world, maxAmmunition), 
    width(width), height(height) { }

FireArm::FireArm(FireArm &&other) : 
    Entity(std::move(other)), loader(std::move(other.loader)),
    width(other.width), height(other.height) {
    other.width = 0;
    other.height = 0;
}

void FireArm::earlyAttachToWorld(float x, float y) {
    setBodyParams(bodyDef, x, y);
    setShapeParams(polygonShape, width, height, x, y);
    setFixtureParams(polygonShape, fixtureDef);
    Entity::attachToWorld(bodyDef, fixtureDef);
}

void FireArm::lateAttachToWorld(float x, float y) {
    setBodyParams(bodyDef, x, y);
    setShapeParams(polygonShape, width, height, x, y);
    setFixtureParams(polygonShape, fixtureDef);
    Entity::attachToWorld(bodyDef, *this);   
}

FireArm::~FireArm() { }

void FireArm::setBodyParams(b2BodyDef &bodyDef, float x, float y) {
    bodyDef.userData = static_cast<void*>(this);
    bodyDef.position.Set(x, y);  
}

void FireArm::setShapeParams(b2PolygonShape &polygonShape,
                             float width, float height,
                             float x, float y) {
    polygonShape.SetAsBox(width, height);   
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
        bullet->shoot(angle, x, y);
        Entity::moveToWorld(std::move(bullet));
    } catch (...) { }
}

void FireArm::reload(size_t &ammunition) {
	loader.reload(ammunition);
}

void FireArm::collideWith(Entity &entity) {
    entity.collideWithFireArm(*this);
}

void FireArm::collideWithBullet(Bullet &bullet) {
    std::cout << "FireArm chocado por bala\n";
}

void FireArm::collideWithObstacle(Obstacle &obstacle) {
    std::cout << "FireArm chocado por obstaculo\n";
}

void FireArm::collideWithFireArm(FireArm &fireArm) {
    std::cout << "FireArm chocado por firearm\n";
}

void FireArm::collideWithPlayer(Player &player) {
    std::cout << "FireArm chocado por player\n";
}

void FireArm::collideWithBorder(Border &border) {
    std::cout << "FireArm chocado por border\n";
}

void FireArm::collideWithKnife(Knife &knife) {
    std::cout << "FireArm chocado por knife" << std::endl;
}

FireArm& FireArm::clone(const FireArm &other) {
    if (this == &other) return *this;
    Entity::clone(other);
    // TODO: SI ALGO FALLA PUEDE QUE SE NECESITE
    // AÑADIR AL MUNDO UN NUEVO BODY CON
    //if (!Entity::isDetached()) { 
    //    attachToWorld(getPositionX(), getPositionY()); 
    //}
    loader.clone(other.loader);
    bodyDef = other.bodyDef;
    polygonShape = other.polygonShape;
    fixtureDef = other.fixtureDef;
    width = other.width;
    height = other.height;
    return *this;
}

void FireArm::setBody(b2Body &body) {
    Entity::setBody(body);
    Entity::bindFixture(fixtureDef);
}
