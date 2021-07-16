#include "World.h"
#include "Entity.h"
#include "Bullet.h"
#include "SWeapon.h"
#include <iostream>

#define TIME_STEP 1.0f/60.0f
#define VELOCITY_ITERATIONS 6
#define POSITION_ITERATIONS 2
#define GRAVITY_X 0.0f
#define GRAVITY_Y 0.0f

World::World() : gravity(GRAVITY_X, GRAVITY_Y),
				 world(gravity),
				 collisionManager(),
				 timeStep(TIME_STEP), 
				 velocityIterations(VELOCITY_ITERATIONS), 
				 positionIterations(POSITION_ITERATIONS) {
	world.SetContactListener(&collisionManager);
}

World::~World() { }

b2Body* World::createBody(const b2BodyDef *bodyDef) {
	return world.CreateBody(bodyDef);
}

void World::createBody(const b2BodyDef &bodyDef, Entity &context) {
	bodiesToCreate.push(std::pair<Entity*, const b2BodyDef*>(&context, &bodyDef));
}

void World::destroyBody(b2Body **body) {
	bodiesToDestroy.push(body);
}

void World::step() {
    world.Step(timeStep, velocityIterations, positionIterations);
    clean();
}

void World::clean() {
	cleanBodiesToDestroy(); // OJO CON EL ORDEN EN QUE LLAMO A LAS FUNCIONES
    cleanBodiesToCreate(); // PUEDE SER FUENTE DE ERROR
	cleanWeapons();
	cleanBullets();
}

void World::cleanBodiesToCreate() {
	b2Body *body = nullptr;
	while(!bodiesToCreate.empty()) {
		std::pair<Entity*, const b2BodyDef*> bodyPair = bodiesToCreate.front();
		body = world.CreateBody(bodyPair.second);
		bodyPair.first->setBody(*body);
		bodiesToCreate.pop();
	}
}

void World::cleanBodiesToDestroy() {
	b2Body **body = nullptr;
	while(!bodiesToDestroy.empty()) {
		body = bodiesToDestroy.front();
		world.DestroyBody(*body);
		*body = nullptr; //OJO CON ESTE NULLPTR QUE PUEDE CAUSAR PROBLEMAS
		// LO AGREGUE POR SEGURIDAD PERO EN CASO DE ERROR ESTE PUEDE SER EL 
		// PROBLEMA
		bodiesToDestroy.pop();
	}
}

void World::cleanWeapons() {
	std::list<std::shared_ptr<SWeapon>>::iterator it = weapons.begin();
	while(it != weapons.end()) {
		if ((*it)->isDetached()) {
			it = weapons.erase(it);
		} else {
			++it;
		}
	}
}

void World::cleanBullets() {
	std::list<std::shared_ptr<Bullet>>::iterator it = bullets.begin();
	while(it != bullets.end()) {
		if ((*it)->isDetached()) { // agregar condicion || (*it)->outOfRange() 
			it = bullets.erase(it);
		} else {
			++it;
		}
	}
}

void World::spawnBullet(std::shared_ptr<Bullet> &&bullet) {
	bullets.push_back(std::move(bullet));
}

void World::spawnWeapon(std::shared_ptr<SWeapon> &&weapon) {
	weapons.push_back(std::move(weapon));
}

std::shared_ptr<SWeapon> World::retrieveSpawnedWeapon(SWeapon &weapon) {
	// SI NO FUE SPAWNEADO EL OBJETO AL MUNDO HABRA UN ERROR
	// PORQUE NO LO ENCONTRARA NUNCA	
	std::list<std::shared_ptr<SWeapon>>::iterator it = weapons.begin();
	std::shared_ptr<SWeapon> spawnedEntity;
	bool found = false;

	while(it != weapons.end() && found == false) {
		if ((*it).get() == &weapon) {
			found = true;
			spawnedEntity = std::move((*it));
			it = weapons.erase(it); // OJO ACA
		} else {
			it++;
		}
	}
	return spawnedEntity;
}

const b2Body* World::getBodyList() const {
	return world.GetBodyList();
}

void World::getServerObjects(std::list<Entity*> &serverObjects){
	serverObjects.clear();
	const b2Body *node = getBodyList();
    while(node != nullptr) {
    	Entity *entity = static_cast<Entity*>(node->GetUserData());
    	if(entity != nullptr) {
    		serverObjects.push_back(entity);
    	}
    	node = node->GetNext();
    }
}

std::ostream& operator<<(std::ostream &os, const World &world) {
    const b2Body *node = world.getBodyList();
    //std::cout << world.world.GetBodyCount() << std::endl;

    while(node != nullptr) {
    	Entity *entity = static_cast<Entity*>(node->GetUserData());
    	//std::cout << entity << std::endl;
    	if(entity != nullptr) {
    		os << *entity << std::endl;
    	}
    	node = node->GetNext();
    }
    return os;
}

void World::getBulletsList(std::list<std::shared_ptr<Bullet>>& newBullets){
	for(auto& bullet: bullets){
		newBullets.push_back(bullet);
	}
}

void World::getWeaponList(std::list<std::shared_ptr<SWeapon>>& newWeapons){
	for(auto& weapon: weapons){
		newWeapons.push_back(weapon);
	}
}
