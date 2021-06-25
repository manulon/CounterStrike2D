#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <Box2D/Box2D.h>
#include <iostream>
class World;

enum EntityID {
	PLAYER,
	BULLET,
	FIRE_ARM,
	OBSTACLE
};

class Entity {
	private:
		EntityID entityID;
		b2Body *body;

		void bindFixtureToEntity(const b2FixtureDef &fixtureDef);
		void bindFixtureToEntity(const b2Shape &shape, float density);
		float radiansToAngle(float radians) const;
		Entity(const Entity &other) = delete;
		Entity& operator=(const Entity &other) = delete;
		Entity& operator=(Entity &&other) = delete;

	public:
		Entity(EntityID entityID);
		Entity(Entity &&other);
		virtual ~Entity();

		void createEntity(World &world, b2BodyDef &bodyDef, 
                          const b2Shape &shape, float density);
		void createEntity(World &world, b2BodyDef &bodyDef, 
						  const b2FixtureDef &fixtureDef);
		void applyForceToCenter(const b2Vec2 &force, bool wake);
		void applyLinearImpulseToCenter(const b2Vec2 &force, 
                             			bool wake);
		float getPositionX() const;
		float getPositionY() const;
		float getAngle() const;
		EntityID getID() const;
		virtual void collideWith(Entity &other) = 0;
		virtual void collidingWithBullet(Entity &other) = 0;
		virtual void collidingWithObstacle(Entity &other) = 0;
		virtual void collidingWithFireArm(Entity &other) = 0;
		virtual void collidingWithPlayer(Entity &other) = 0;
		

};
	
#endif // _ENTITY_H_
