#ifndef _WORLD_H_
#define _WORLD_H_

#include <Box2D/Box2D.h>

class World {
	private:
		b2Vec2 gravity;
		b2World world;
		float timeStep;
		int32 velocityIterations;
		int32 positionIterations;

	public: 
		World();
		~World();
		void createBoundaries();
		void step();
		b2Body *createBody(const b2BodyDef *def);
};

#endif // _WORLD_H_
