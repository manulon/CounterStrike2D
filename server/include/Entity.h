#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <Box2D/Box2D.h>
#include <iostream>
class World;
class Bullet;
class Obstacle;
class FireArm;
class Player;
class Border;

class Entity {
	private:
		b2Body *body;
		World &world;
		bool detached;

		void bindFixture(const b2Shape &shape, float density);
		float radiansToAngle(float radians) const;
		Entity(const Entity &other) = delete;
		Entity& operator=(const Entity &other) = delete;
		Entity& operator=(Entity &&other) = delete;

	public:		
		Entity(World &world);
		Entity(Entity &&other);
		virtual ~Entity();

		virtual void collideWith(Entity &entity) = 0;
		virtual void collideWithBullet(Bullet &bullet) = 0;
		virtual void collideWithObstacle(Obstacle &obstacle) = 0;
		virtual void collideWithFireArm(FireArm &fireArm) = 0;
		virtual void collideWithPlayer(Player &player) = 0;
		virtual void collideWithBorder(Border &border) = 0;
		void attachToWorld(b2BodyDef &bodyDef, const b2Shape &shape, 
				  float density);
		void attachToWorld(b2BodyDef &bodyDef, const b2FixtureDef &fixtureDef);
		void detachFromWorld();
		void applyForceToCenter(const b2Vec2 &force, bool wake);
		void applyLinearImpulseToCenter(const b2Vec2 &force, 
                             			bool wake);
		void bindFixture(const b2FixtureDef &fixtureDef);
		float getPositionX() const;
		float getPositionY() const;
		float getAngle() const;
		friend std::ostream& operator<<(std::ostream &os, const Entity &entity);
		void moveToWorld(std::unique_ptr<Entity> &&entity);
		bool isDetached();
		void setTransform(float x, float y, float angle);

};
	
#endif // _ENTITY_H_
