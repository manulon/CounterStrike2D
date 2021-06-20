#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <Box2D/Box2D.h>
#include <cmath>
class World;

class Player {
	private:
		b2Body *body;
		b2Vec2 force;
		void setBodyParams(b2BodyDef &bodyDef, float x, float y);
		void createBody(World &world, b2BodyDef &bodyDef);
		void setShapeParams(b2PolygonShape &polygonShape,
                      		float width, float height);
		void setFixtureParams(const b2PolygonShape &polygonShape, 
							  b2FixtureDef &fixtureDef);
		void bindFixtureToBody(const b2FixtureDef &fixtureDef);

		Player(const Player &other) = delete;
		Player& operator=(const Player &other) = delete;
		Player& operator=(Player &&other) = delete;

	public:
		Player(World &world, 
               float x, float y,
               float width, float height);
		Player(Player &&other);
		~Player();
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
