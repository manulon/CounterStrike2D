#include "SWeapon.h"
#include "WeaponType.h"

#define DENSITY 1.0f

SWeapon::SWeapon(World &world, 
                 std::unique_ptr<WeaponType> &&other) : 
    Entity(world, 14),
    weaponType(std::move(other)) {
    weaponType->setContext(this);
}

SWeapon::SWeapon(SWeapon &&other) :
    Entity(std::move(other)),
    weaponType(std::move(other.weaponType)) {
}

SWeapon::~SWeapon() { }

void SWeapon::setBodyParams(b2BodyDef &bodyDef, float x, float y) {
    bodyDef.userData = static_cast<void*>(this);
    bodyDef.position.Set(x, y);
}

void SWeapon::setShapeParams(b2PolygonShape &polygonShape,
                             float width, float height,
                             float x, float y) {
    polygonShape.SetAsBox(width, height);   
}

void SWeapon::setFixtureParams(const b2PolygonShape &polygonShape, 
                               b2FixtureDef &fixtureDef) {
    fixtureDef.shape = &polygonShape;
    fixtureDef.density = DENSITY;
    fixtureDef.filter.categoryBits = SWEAPON;
}

void SWeapon::earlyAttachToWorld(float x, float y) {
    setBodyParams(bodyDef, x, y);
    setShapeParams(polygonShape, 
                   weaponType->getWidth(), 
                   weaponType->getHeight(),
                   x, y);
    setFixtureParams(polygonShape, fixtureDef);
    Entity::earlyAttachToWorld(bodyDef, fixtureDef);
}

void SWeapon::lateAttachToWorld(float x, float y) {
    setBodyParams(bodyDef, x, y);
    setShapeParams(polygonShape, 
                   weaponType->getWidth(), 
                   weaponType->getHeight(),
                   x, y);
    setFixtureParams(polygonShape, fixtureDef);
    Entity::lateAttachToWorld(bodyDef, *this);
}

void SWeapon::attack(float angle, float x, float y) {
    weaponType->attack(angle, x, y);
}

void SWeapon::reload(size_t &ammunition) {
    weaponType->reload(ammunition);
}

void SWeapon::collideWith(Entity &entity) {
    entity.collideWithWeapon(*this);
}

void SWeapon::collideWithBullet(Bullet &bullet) {
}

void SWeapon::collideWithObstacle(Obstacle &obstacle) {
}

void SWeapon::collideWithPlayer(Player &player) {
    weaponType->collideWithPlayer(player);
}

void SWeapon::collideWithBorder(Border &border) {
}

void SWeapon::collideWithWeapon(SWeapon &Weapon) {
}

void SWeapon::setBody(b2Body &body) {
    Entity::setBody(body);
    Entity::bindFixture(fixtureDef);
}

bool SWeapon::playerIsInWeapon(int x, int y){
    if ( (x > (getPositionX() - weaponType->getWidth()) && 
          x < (getPositionX() + weaponType->getWidth()) &&
         (y > (getPositionY() - weaponType->getHeight())&&
          y < (getPositionY() + weaponType->getHeight()) ))) {
         return true;
    }
    return false;
}

short SWeapon::getId(){
    return weaponType->getId();
}
