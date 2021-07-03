#ifndef _KINFE_H_
#define _KINFE_H_

#include "Entity.h"

class Knife : public Entity {
	private:
		b2BodyDef bodyDef;
    	b2PolygonShape polygonShape;
    	b2FixtureDef fixtureDef;

    	void setBodyParams(b2BodyDef &bodyDef, float x, float y);
		void setShapeParams(b2PolygonShape &polygonShape);
		void setFixtureParams(const b2PolygonShape &polygonShape, 
						      b2FixtureDef &fixtureDef);
    	void earlyAttachToWorld(float x, float y);
		float angleToRadians(float angle);

	public:
		Knife(World &world);
		Knife(Knife &&other);
		~Knife();

		virtual void collideWith(Entity &entity) override;
		virtual void collideWithBullet(Bullet &bullet) override;
		virtual void collideWithObstacle(Obstacle &obstacle) override;
		virtual void collideWithFireArm(FireArm &fireArm) override;
		virtual void collideWithPlayer(Player &player) override;
		virtual void collideWithBorder(Border &border) override;
		virtual void collideWithKnife(Knife &knife) override;

		virtual void setBody(b2Body &body) override;
		void attack(float angle, float x, float y);
};

#endif // _KINFE_H_
