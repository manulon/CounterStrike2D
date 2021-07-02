#ifndef _OBSTACLE_H_
#define _OBSTACLE_H_

#include "Entity.h"
#include <Box2D/Box2D.h>
class World;

class Obstacle : public Entity {
	private:
		b2BodyDef bodyDef;
		b2PolygonShape polygonShape;
		
		Obstacle(const Obstacle &other) = delete;
		Obstacle& operator=(const Obstacle &other) = delete;
		Obstacle& operator=(Obstacle &&other) = delete;
		void setBodyParams(b2BodyDef &bodyDef, float x, float y);
		void setShapeParams(b2PolygonShape &polygonShape,
                      		float width, float height);

	public:
		Obstacle(World &world, 
				 float x, float y,
				 float width, float height);
		Obstacle(Obstacle &&other);
		~Obstacle();
		virtual void collideWith(Entity &entity) override;
		virtual void collideWithBullet(Bullet &bullet) override;
		virtual void collideWithObstacle(Obstacle &obstacle) override;
		virtual void collideWithFireArm(FireArm &fireArm) override;
		virtual void collideWithPlayer(Player &player) override;
		virtual void collideWithBorder(Border &border) override;
		virtual void setBody(b2Body &body) override;
};

#endif // _OBSTACLE_H_
