#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <Box2D/Box2D.h>
#include <iostream>
class World;
class Bullet;
class Obstacle;
class SWeapon;
class Player;
class Border;

class Entity {
	private:
		b2Body *body;
		World &world;
		bool detached;
		short id;
		Entity(const Entity &other) = delete;
		Entity& operator=(const Entity &other) = delete;
		Entity& operator=(Entity &&other) = delete;
		float radiansToAngle(float radians) const;

	public:		
		Entity(World &world, short id);
		Entity(Entity &&other);
		virtual ~Entity();

		virtual void collideWith(Entity &entity) = 0;
		virtual void collideWithBullet(Bullet &bullet) = 0;
		virtual void collideWithObstacle(Obstacle &obstacle) = 0;
		virtual void collideWithWeapon(SWeapon &weapon) = 0;
		virtual void collideWithPlayer(Player &player) = 0;
		virtual void collideWithBorder(Border &border) = 0;
		virtual void setBody(b2Body &body);

		void earlyAttachToWorld(b2BodyDef &bodyDef, const b2FixtureDef &fixtureDef);
		void lateAttachToWorld(b2BodyDef &bodyDef, Entity &context);
		void detachFromWorld();
		void bindFixture(const b2FixtureDef &fixtureDef);
		void setTransform(float x, float y, float angle);
		bool isDetached();
		void applyForceToCenter(const b2Vec2 &force, bool wake);
		void applyLinearImpulseToCenter(const b2Vec2 &force, 
                             			bool wake);
		friend std::ostream& operator<<(std::ostream &os, const Entity &entity);
		float getPositionX() const;
		float getPositionY() const;
		float getAngle() const;
		World& getWorld();
		short getId() const ;
};
	
#endif // _ENTITY_H_
