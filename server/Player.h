#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <Box2D/Box2D.h>
#include <math.h>
#include <cmath>
#define PI 3.14159265
class World;

class Player {
	private:
		b2Body *body;
		b2Vec2 force;
	public:
		Player(World &world, 
               float x, float y,
               float width, float height);
		~Player();
		void initBody(World &world, 
                      float x, float y,
                      float width, float height);
		void setShape(b2PolygonShape &polygonShape,
                      float width, float height);
		void setFixture(const b2PolygonShape &polygonShape, 
						b2FixtureDef &fixtureDef);
		float getPosition_x() const;
		float getPosition_y() const;
		float getAngle() const;
		void moveRight();
		void moveLeft();
		void moveUp();
		void moveDown();
		void stopMoveDown();
		void stopMoveUp();
		void stopMoveLeft();
		void stopMoveRight();
		void update();
};

#endif // _PLAYER_H_
