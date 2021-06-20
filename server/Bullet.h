#ifndef _BULLET_H_
#define _BULLET_H_

#include <Box2D/Box2D.h>
class World;

class Bullet {
	private:
		b2Body *body;
		void setBodyParams(b2BodyDef &bodyDef, float x, float y);
		void createBody(World &world, b2BodyDef &bodyDef);
		void setCircleParams(b2CircleShape &circleShape);
		void setFixtureParams(const b2CircleShape &circleShape, 
		                      b2FixtureDef &fixtureDef);
		void bindFixtureToBody(const b2FixtureDef &fixtureDef);
		float angleToRadians(float angle);
		
		Bullet(const Bullet &other) = delete;
		Bullet& operator=(const Bullet &other) = delete;
		Bullet& operator=(Bullet &&other) = delete;

	public:
		Bullet(World &world, float x, float y);
		Bullet(Bullet &&other);
		~Bullet();
		void shoot(float angle);
		float getPosition_x() const;
		float getPosition_y() const;
		float getAngle() const;
};

#endif // _BULLET_H_
