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
	    b2BodyDef bodyDef;
    	b2PolygonShape polygonShape;
		b2FixtureDef fixtureDef;
		float width;
		float height;
		//float x, y;
		//float xOrigin, yOrigin;

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
		void shoot(float angle, float x, float y);
		void reload(size_t &ammunition);
		virtual void collideWith(Entity &entity) override;
		virtual void collideWithBullet(Bullet &bullet) override;
		virtual void collideWithObstacle(Obstacle &obstacle) override;
		virtual void collideWithFireArm(FireArm &fireArm) override;
		virtual void collideWithPlayer(Player &player) override;
		virtual void collideWithBorder(Border &border) override;

		void earlyAttachToWorld(float x, float y);
		void lateAttachToWorld(float x, float y);
		void drop(float x, float y);
		//void attachToPlayer(Player &player,float xOrigin, 
        //sfloat yOrigin, float x, float y);
        FireArm& clone(const FireArm &other);
        
       	virtual void setBody(b2Body &body) override;
};

#endif // _FIRE_ARM_H_
