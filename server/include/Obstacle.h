#ifndef _OBSTACLE_H_
#define _OBSTACLE_H_

#include "Entity.h"
#include <Box2D/Box2D.h>
class World;

class Obstacle : public Entity {
	private:
		b2BodyDef bodyDef;
    	b2PolygonShape polygonShape;
    	b2FixtureDef fixtureDef;
		
		Obstacle(const Obstacle &other) = delete;
		Obstacle& operator=(const Obstacle &other) = delete;
		Obstacle& operator=(Obstacle &&other) = delete;
		void setBodyParams(b2BodyDef &bodyDef, float x, float y);
		void setShapeParams(b2PolygonShape &polygonShape,
                      		float width, float height);
		void setFixtureParams(const b2PolygonShape &polygonShape, 
							  b2FixtureDef &fixtureDef);

	public:
		Obstacle(World &world, 
				 float x, float y,
				 float width, float height);
		Obstacle(Obstacle &&other);
		~Obstacle();
		virtual void collideWith(Entity &entity) override;
		virtual void collideWithBullet(Bullet &bullet) override;
		virtual void collideWithObstacle(Obstacle &obstacle) override;
		virtual void collideWithWeapon(SWeapon &weapon) override;
		virtual void collideWithPlayer(Player &player) override;
		virtual void collideWithBorder(Border &border) override;
		virtual void setBody(b2Body &body) override;
};

#endif // _OBSTACLE_H_
