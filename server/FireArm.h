#ifndef _FIRE_ARM_H_
#define _FIRE_ARM_H_

#include "Entity.h"
#include "Bullet.h"
#include "Loader.h"
#include <Box2D/Box2D.h>
#include <cstddef>

class World;

class FireArm : public Entity {
	private:
		void setBodyParams(b2BodyDef &bodyDef, float x, float y);
		void setShapeParams(b2PolygonShape &polygonShape,
                      		float width, float height);
		void setFixtureParams(const b2PolygonShape &polygonShape, 
							  b2FixtureDef &fixtureDef);

		FireArm(const FireArm &other) = delete;
		FireArm& operator=(const FireArm &other) = delete;
		FireArm& operator=(FireArm &&other) = delete;

	public:
		Bullet bullet;
		Loader loader;
		FireArm(World &world, 
				float x, float y,
				float width, float height, 
				Bullet &&bullet, Loader &&loader);
		FireArm(FireArm &&other);
		~FireArm();
		void shoot(float angle);
		void reload(size_t &ammunition);
		virtual void collidingWithObstacle(Entity &other) override;
		virtual void collidingWithFireArm(Entity &other) override;
		virtual void collidingWithBullet(Entity &other) override;
		virtual void collidingWithPlayer(Entity &other) override;
		virtual void collideWith(Entity &other) override;
};

#endif // _FIRE_ARM_H_
