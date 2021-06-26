#include "Border.h"
#define DENSITY 1.0f

Border::Border(World &world) : Entity() {
	b2BodyDef groundBodyDef;
    b2PolygonShape groundBox;
    setBodyParams(groundBodyDef, 0.0f, 0.0f);
    setShapeParams(groundBox, 50.0f, 0.0f);
    init(world, groundBodyDef, groundBox, DENSITY);
}

Border::~Border() { }

void Border::setBodyParams(b2BodyDef &bodyDef, float x, float y) {
    bodyDef.userData = static_cast<void*>(this);
	bodyDef.position.Set(x, y);
}

void Border::setShapeParams(b2PolygonShape &polygonShape,
                      		float width, float height) {
    polygonShape.SetAsBox(width, height);	
}

void Border::collideWith(Entity &entity) {
    entity.collideWithBorder(*this);
}

void Border::collideWithBullet(Bullet &bullet) {
    std::cout << "Border chocado por bala\n";
}

void Border::collideWithObstacle(Obstacle &obstacle) {
    std::cout << "Border chocado por obstaculo\n";
}

void Border::collideWithFireArm(FireArm &fireArm) {
    std::cout << "Border chocado por firearm\n";
}

void Border::collideWithPlayer(Player &player) {
    std::cout << "Border chocado por player\n";
}

void Border::collideWithBorder(Border &border) {
    std::cout << "Border chocado por border\n";
}
