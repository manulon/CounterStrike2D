	#ifndef _BORDER_H_
#define _BORDER_H_

#include "Entity.h"
#include <Box2D/Box2D.h>
#include <memory>
class World;

class Border : public Entity {
	private:
		b2BodyDef borderDef;
    	b2PolygonShape side;
    	b2FixtureDef fixtureDef;
    	float x;
    	float y;
    	float width;
    	float height;

		void setBodyParams(b2BodyDef &bodyDef, float x, float y);
		void setFixtureParams(const b2PolygonShape &polygonShape, 
                              b2FixtureDef &fixtureDef);
	public:
		Border(World &world, 
			   float x, float y,
               float width, float height);
		Border(Border &&other);
		~Border();
		virtual void collideWith(Entity &entity) override;
		virtual void collideWithBullet(Bullet &bullet) override;
		virtual void collideWithObstacle(Obstacle &obstacle) override;
		virtual void collideWithFireArm(FireArm &fireArm) override;
		virtual void collideWithPlayer(Player &player) override;
		virtual void collideWithBorder(Border &border) override;

		virtual void setBody(b2Body &body) override;
};

#endif // _BORDER_H_
