#ifndef _WORLD_H_
#define _WORLD_H_

#include "CollisionManager.h"
#include <Box2D/Box2D.h>
#include <queue>

class World {
	private:
		b2Vec2 gravity;
		b2World world;
		CollisionManager collisionHandler;
		float timeStep;
		int32 velocityIterations;
		int32 positionIterations;

		std::queue<b2Body*> destroyList;

		void makeBoundaries();
		World(const World &other) = delete;
		World& operator=(const World &other) = delete;
		World& operator=(World &&other) = delete;
		World(World &&other) = delete;

	public: 
		World();
		~World();
		void step();
		b2Body *createBody(const b2BodyDef *def);
		friend std::ostream& operator<<(std::ostream &os, const World &obj);
		const b2Body* getBodyList() const;
		
		void clean();
		void destroy(b2Body &body);
};

#endif // _WORLD_H_
