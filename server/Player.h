#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <Box2D/Box2D.h>
class World;

class Player {
	private:
		b2Body *body;

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
};

#endif // _PLAYER_H_
