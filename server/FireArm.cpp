#include "FireArm.h"

#define DENSITY 1.0f
#define FRICTION 0.0f
#define BODY_TYPE b2_dynamicBody

FireArm::FireArm(World &world, 
				 float x, float y,
				 float width, float height, 
				 Bullet &&bullet, Loader &&loader) : 
	Entity(EntityID::FIRE_ARM), 
	bullet(std::move(bullet)),
	loader(std::move(loader)) { 
    b2BodyDef bodyDef;
    b2PolygonShape polygonShape;
    b2FixtureDef fixtureDef;
    setBodyParams(bodyDef, x, y);
    setShapeParams(polygonShape, width, height);
    setFixtureParams(polygonShape, fixtureDef);

    createEntity(world, bodyDef, fixtureDef);
}

FireArm::FireArm(FireArm &&other) : 
	Entity(std::move(other)),
	bullet(std::move(other.bullet)),
	loader(std::move(other.loader)) { }

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

void FireArm::collidingWithBullet(Entity &other){
    std::cout<<"obstaculo chocado por bala\n";
}
void FireArm::collidingWithPlayer(Entity &other){
    std::cout<<"FireArm chocado por player\n";
}
void FireArm::collidingWithFireArm(Entity &other){
    std::cout<<"FireArm chocado por firearm\n";
}
void FireArm::collidingWithObstacle(Entity &other){
    std::cout<<"FireArm chocado por obstavulo\n";
}

void FireArm::collideWith(Entity &other){
    other.collidingWithFireArm(*this);
}
