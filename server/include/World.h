#ifndef _WORLD_H_
#define _WORLD_H_

#include "CollisionManager.h"
#include <Box2D/Box2D.h>
#include <queue>

class World {
	private:
		b2Vec2 gravity;
		b2World world;
		CollisionManager collisionManager;
		std::queue<b2Body*> bodiesToDestroy;
		float timeStep;
		int32 velocityIterations;
		int32 positionIterations;

		World(const World &other) = delete;
		World& operator=(const World &other) = delete;
		World& operator=(World &&other) = delete;
		World(World &&other) = delete;
		void clean();
		const b2Body* getBodyList() const;

	public: 
		World();
		~World();
		void step();
		b2Body* createBody(const b2BodyDef *bodyDef);
		void destroy(b2Body &body);
		friend std::ostream& operator<<(std::ostream &os, const World &world);
};

#endif // _WORLD_H_
