#include "World.h"
#include "Entity.h"

#define TIME_STEP 1.0f/60.0f
#define VELOCITY_ITERATIONS 6
#define POSITION_ITERATIONS 2
#define GRAVITY_X 0.0f
#define GRAVITY_Y 0.0f

World::World() : gravity(GRAVITY_X, GRAVITY_Y),
				 world(gravity),
				 collisionHandler(),
				 timeStep(TIME_STEP), 
				 velocityIterations(VELOCITY_ITERATIONS), 
				 positionIterations(POSITION_ITERATIONS) {
	world.SetContactListener(&collisionHandler);
}

World::~World() { }

void World::step() {
    world.Step(timeStep, velocityIterations, positionIterations);
    clean();
}

b2Body* World::createBody(const b2BodyDef *def) {
	return world.CreateBody(def);
}

const b2Body* World::getBodyList() const {
	return world.GetBodyList();
}

void World::destroy(b2Body &body) {
	destroyList.push(&body);
}

void World::clean() {
	b2Body *body = nullptr;
	while(!destroyList.empty()) {
		body = destroyList.front();
		world.DestroyBody(body);
		destroyList.pop();
	}
}

std::ostream& operator<<(std::ostream &os, const World &obj) {
    const b2Body *node = obj.getBodyList();
    while(node != nullptr) {
    	Entity *entity = static_cast<Entity*>(node->GetUserData());
    	if(entity != nullptr) {
    		os << *entity << std::endl;
    	}
    	node = node->GetNext();
    }
    return os;
}
