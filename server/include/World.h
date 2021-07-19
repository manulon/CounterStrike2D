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

		World(const World &other) = delete;
		World& operator=(const World &other) = delete;
		World& operator=(World &&other) = delete;
		World(World &&other) = delete;
		void clean();
		void cleanBodiesToCreate();
		void cleanBodiesToDestroy();
		void cleanWeapons();
		void cleanBullets();
		const b2Body* getBodyList() const;

	public: 
		/*CAMBIAR A PRIVATE*/
		b2Vec2 gravity;
		b2World world;
		CollisionManager collisionManager;
		std::queue<std::pair<Entity*, const b2BodyDef*>> bodiesToCreate;
		std::queue<b2Body**> bodiesToDestroy;
		float timeStep;
		int32 velocityIterations;
		int32 positionIterations;

		std::list<std::shared_ptr<SWeapon>> weapons;
		std::list<std::shared_ptr<Bullet>> bullets;

		World();
		~World();
		void step(float rate);
		b2Body* createBody(const b2BodyDef *bodyDef);
		void destroyBody(b2Body **body);
		void spawnBullet(std::shared_ptr<Bullet> &&bullet);
		void spawnWeapon(std::shared_ptr<SWeapon> &&weapon);
		std::shared_ptr<SWeapon> retrieveSpawnedWeapon(SWeapon &weapon);
		friend std::ostream& operator<<(std::ostream &os, const World &world);

		void createBody(const b2BodyDef &bodyDef, Entity &context);
		void getServerObjects(std::list<Entity*> &serverObjects);
		void getBulletsList(std::list<std::shared_ptr<Bullet>>& bullets);
		void getWeaponList(std::list<std::shared_ptr<SWeapon>>& weapons);
};

#endif // _WORLD_H_
