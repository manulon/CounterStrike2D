#ifndef _BORDER_H_
#define _BORDER_H_

#include "Entity.h"
#include <Box2D/Box2D.h>
class World;

class Border : public Entity {
	public:
		Border(World &world);
		~Border();
		void setBodyParams(b2BodyDef &bodyDef, float x, float y);
		void setShapeParams(b2PolygonShape &polygonShape,
                      		float width, float height);
		virtual void collideWith(Entity &entity) override;
		virtual void collideWithBullet(Bullet &bullet) override;
		virtual void collideWithObstacle(Obstacle &obstacle) override;
		virtual void collideWithFireArm(FireArm &fireArm) override;
		virtual void collideWithPlayer(Player &player) override;
		virtual void collideWithBorder(Border &border) override;
};

#endif // _BORDER_H_
