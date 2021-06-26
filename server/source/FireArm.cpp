#include "FireArm.h"

#define DENSITY 1.0f
#define FRICTION 0.0f
#define BODY_TYPE b2_dynamicBody

FireArm::FireArm(World &world, 
				 float x, float y,
				 float width, float height, 
				 Bullet &bullet, Loader &loader) : 
	Entity(), 
	bullet(bullet),
	loader(loader) { 
    b2BodyDef bodyDef;
    b2PolygonShape polygonShape;
    b2FixtureDef fixtureDef;
    setBodyParams(bodyDef, x, y);
    setShapeParams(polygonShape, width, height);
    setFixtureParams(polygonShape, fixtureDef);

    init(world, bodyDef, fixtureDef);
}

FireArm::FireArm(FireArm &&other) : 
	Entity(std::move(other)),
	bullet(other.bullet),
	loader(other.loader) { }

FireArm::~FireArm() { }

void FireArm::setBodyParams(b2BodyDef &bodyDef, float x, float y) {
    bodyDef.userData = static_cast<void*>(this);
    /* TODO 
     * ME PARECE QUE EL ARMA DEBERIA SER ESTATICO
     * POR ESO AUN NO HABILITO TYPE A SER DINAMICO
     */
    //bodyDef.type = BODY_TYPE;
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
	if (!loader.isEmpty()) {
		bullet.shoot(angle);
		loader.releaseAmmunition();
	}
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
