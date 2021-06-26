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
		virtual void collideWith(Entity &entity) override;
		virtual void collideWithBullet(Bullet &bullet) override;
		virtual void collideWithObstacle(Obstacle &obstacle) override;
		virtual void collideWithFireArm(FireArm &fireArm) override;
		virtual void collideWithPlayer(Player &player) override;
		virtual void collideWithBorder(Border &border) override;
};

#endif // _OBSTACLE_H_
