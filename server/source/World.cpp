#include "World.h"
#include "Entity.h"
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

void World::cleanBodiesToCreate() {
	b2Body *body = nullptr;
	while(!bodiesToCreate.empty()) {
		std::pair<Entity*, const b2BodyDef*> bodyPair = bodiesToCreate.front();
		body = world.CreateBody(bodyPair.second);
		bodyPair.first->setBody(*body);
		bodiesToCreate.pop();
	}
}

void World::destroyBody(b2Body **body) {
	bodiesToDestroy.push(body);
}

void World::step() {
    world.Step(timeStep, velocityIterations, positionIterations);
    clean();
}

void World::clean() {
    cleanBodiesToCreate();
	cleanBodiesToDestroy();
	cleanDetachedEntities();
}

const b2Body* World::getBodyList() const {
	return world.GetBodyList();
}

void World::spawnEntity(std::unique_ptr<Entity> &&entity) {
	entities.push_back(std::move(entity));
}

void World::cleanBodiesToDestroy() {
	b2Body **body = nullptr;
	while(!bodiesToDestroy.empty()) {
		body = bodiesToDestroy.front();
		world.DestroyBody(*body);
		*body = nullptr;
		bodiesToDestroy.pop();
	}
}

void World::cleanDetachedEntities() {
	std::list<std::unique_ptr<Entity>>::iterator it = entities.begin();
	while(it != entities.end()) {
		if ((*it)->isDetached()) {
			it = entities.erase(it);
		} else {
			++it;
		}
	}
}

std::ostream& operator<<(std::ostream &os, const World &world) {
    const b2Body *node = world.getBodyList();
    while(node != nullptr) {
    	Entity *entity = static_cast<Entity*>(node->GetUserData());
    	if(entity != nullptr) {
    		os << *entity << std::endl;
    	}
    	node = node->GetNext();
    }
    return os;
}
