#ifndef _WORLD_H_
#define _WORLD_H_

#include "CollisionManager.h"
#include "Entity.h"
#include <Box2D/Box2D.h>
#include <queue>
#include <list>
#include <utility>

class World {
	private:
		b2Vec2 gravity;
		b2World world;
		CollisionManager collisionManager;
		std::list<std::unique_ptr<Entity>> entities;
		std::queue<std::pair<Entity*, const b2BodyDef*>> bodiesToCreate;
		std::queue<b2Body**> bodiesToDestroy;
		float timeStep;
		int32 velocityIterations;
		int32 positionIterations;

		World(const World &other) = delete;
		World& operator=(const World &other) = delete;
		World& operator=(World &&other) = delete;
		World(World &&other) = delete;
		void clean();
		void cleanBodiesToDestroy();
		void cleanDetachedEntities();
		const b2Body* getBodyList() const;

	public: 
		World();
		~World();
		void step();
		b2Body* createBody(const b2BodyDef *bodyDef);
		void destroyBody(b2Body **body);
		void spawnEntity(std::unique_ptr<Entity> &&entity);
		friend std::ostream& operator<<(std::ostream &os, const World &world);

		void createBody(const b2BodyDef &bodyDef, Entity &context);
		void cleanBodiesToCreate();
};

#endif // _WORLD_H_
