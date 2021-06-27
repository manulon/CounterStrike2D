#include "World.h"
#include "Entity.h"

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

void World::destroy(b2Body &body) {
	bodiesToDestroy.push(&body);
}

void World::step() {
    world.Step(timeStep, velocityIterations, positionIterations);
    clean();
}

void World::clean() {
	b2Body *body = nullptr;
	while(!bodiesToDestroy.empty()) {
		body = bodiesToDestroy.front();
		world.DestroyBody(body);
		bodiesToDestroy.pop();
	}
}

const b2Body* World::getBodyList() const {
	return world.GetBodyList();
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
