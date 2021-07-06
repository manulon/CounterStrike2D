#ifndef _BULLET_H_
#define _BULLET_H_

#include "Entity.h"
#include <Box2D/Box2D.h>
class World;

class Bullet : public Entity {
	private:
		b2BodyDef bodyDef;
    	b2CircleShape circleShape;
		b2FixtureDef fixtureDef;

		void setBodyParams(b2BodyDef &bodyDef, float x, float y);
		void setShapeParams(b2CircleShape &circleShape);
		void setFixtureParams(const b2CircleShape &circleShape, 
		                      b2FixtureDef &fixtureDef);
		float angleToRadians(float angle);
		
		Bullet(const Bullet &other) = delete;
		Bullet& operator=(const Bullet &other) = delete;
		Bullet& operator=(Bullet &&other) = delete;

	public:
		Bullet(World &world);
		Bullet(Bullet &&other);
		~Bullet();
		virtual void collideWith(Entity &entity) override;
		virtual void collideWithBullet(Bullet &bullet) override;
		virtual void collideWithObstacle(Obstacle &obstacle) override;
		virtual void collideWithFireArm(FireArm &fireArm) override;
		virtual void collideWithPlayer(Player &player) override;
		virtual void collideWithBorder(Border &border) override;
		virtual void collideWithKnife(Knife &knife) override;
		virtual void setBody(b2Body &body) override;
		
		void attachToWorld(float x, float y);
		void shoot(float angle, float x, float y);
		float getRadius();
		//friend std::ostream& operator<<(std::ostream &os, const Bullet &obj);
		//Bullet& clone(const Bullet &other);

};

#endif // _BULLET_H_
