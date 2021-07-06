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
		std::queue<std::pair<Entity*, const b2BodyDef*>> bodiesToCreate;
		std::queue<b2Body**> bodiesToDestroy;
		float timeStep;
		int32 velocityIterations;
		int32 positionIterations;

		std::list<std::unique_ptr<FireArm>> fireArms;
		std::list<std::unique_ptr<Bullet>> bullets;

		World(const World &other) = delete;
		World& operator=(const World &other) = delete;
		World& operator=(World &&other) = delete;
		World(World &&other) = delete;
		void clean();
		void cleanBodiesToCreate();
		void cleanBodiesToDestroy();
		void cleanFireArms();
		void cleanBullets();
		const b2Body* getBodyList() const;

	public: 
		World();
		~World();
		void step();
		b2Body* createBody(const b2BodyDef *bodyDef);
		void destroyBody(b2Body **body);
		void spawnBullet(std::unique_ptr<Bullet> &&bullet);
		void spawnFireArm(std::unique_ptr<FireArm> &&fireArm);
		std::unique_ptr<FireArm> retrieveSpawnedFireArm(FireArm &fireArm);
		friend std::ostream& operator<<(std::ostream &os, const World &world);

		void createBody(const b2BodyDef &bodyDef, Entity &context);
		void getServerObjects(std::list<Entity*> &serverObjects);
};

#endif // _WORLD_H_
