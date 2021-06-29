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
		Loader loader;
		float width;
		float height;
		float x, y;
		float xOrigin, yOrigin;

		void setBodyParams(b2BodyDef &bodyDef, float x, float y);
		void setShapeParams(b2PolygonShape &polygonShape,
                      		float width, float height,
                            float x, float y);
		void setFixtureParams(const b2PolygonShape &polygonShape, 
							  b2FixtureDef &fixtureDef);
		void setBulletPosition(std::unique_ptr<Bullet> &bullet, float angle);

		FireArm(const FireArm &other) = delete;
		FireArm& operator=(const FireArm &other) = delete;
		FireArm& operator=(FireArm &&other) = delete;

	public:
		FireArm(World &world, 
				float width, float height,
                size_t maxAmmunition);
		FireArm(FireArm &&other);
		~FireArm();
		void shoot(float angle);
		void reload(size_t &ammunition);
		virtual void collideWith(Entity &entity) override;
		virtual void collideWithBullet(Bullet &bullet) override;
		virtual void collideWithObstacle(Obstacle &obstacle) override;
		virtual void collideWithFireArm(FireArm &fireArm) override;
		virtual void collideWithPlayer(Player &player) override;
		virtual void collideWithBorder(Border &border) override;

		void attachToWorld(float x, float y);
		void attachToPlayer(Player &player,float xOrigin, 
        float yOrigin, float x, float y);
};

#endif // _FIRE_ARM_H_
