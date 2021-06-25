#ifndef _OBSTACLE_H_
#define _OBSTACLE_H_

#include "Entity.h"
#include <Box2D/Box2D.h>
class World;

class Obstacle : public Entity {
	private:
		void setBodyParams(b2BodyDef &bodyDef, float x, float y);
		void setShapeParams(b2PolygonShape &polygonShape,
                      		float width, float height);

		Obstacle(const Obstacle &other) = delete;
		Obstacle& operator=(const Obstacle &other) = delete;
		Obstacle& operator=(Obstacle &&other) = delete;

	public:
		Obstacle(World &world, 
				 float x, float y,
				 float width, float height);
		Obstacle(Obstacle &&other);
		~Obstacle();
		virtual void collidingWithObstacle(Entity &other) override;
		virtual void collidingWithFireArm(Entity &other) override;
		virtual void collidingWithBullet(Entity &other) override;
		virtual void collidingWithPlayer(Entity &other) override;
		virtual void collideWith(Entity &other) override;
};

#endif // _OBSTACLE_H_
