#ifndef _BULLET_H_
#define _BULLET_H_

#include "Entity.h"
#include <Box2D/Box2D.h>
class World;

class Bullet : public Entity {
	private:
		void setBodyParams(b2BodyDef &bodyDef, float x, float y);
		void setShapeParams(b2CircleShape &circleShape);
		void setFixtureParams(const b2CircleShape &circleShape, 
		                      b2FixtureDef &fixtureDef);
		float angleToRadians(float angle);
		
		Bullet(const Bullet &other) = delete;
		Bullet& operator=(const Bullet &other) = delete;
		Bullet& operator=(Bullet &&other) = delete;

	public:
		Bullet(World &world, float x, float y);
		Bullet(Bullet &&other);
		~Bullet();
		void shoot(float angle);
};

#endif // _BULLET_H_
