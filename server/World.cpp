#include "World.h"

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
	makeBoundaries();
	world.SetContactListener(&collisionHandler);
}

World::~World() { }

void World::makeBoundaries() {
	// TODO REFACTORIZAR A LOS LIMITES CORRECTOS DEL MAPA
	// CUANDO SEPAMOS COMO SERIAN.

    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, -10.0f);
    b2Body* groundBody = world.CreateBody(&groundBodyDef);
    b2PolygonShape groundBox;
    groundBox.SetAsBox(50.0f, 0.0f);
    groundBody->CreateFixture(&groundBox, 0.0f);
}

void World::step() {
    world.Step(timeStep, velocityIterations, positionIterations);
}

b2Body* World::createBody(const b2BodyDef *def) {
	return world.CreateBody(def);
}