#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Entity.h"
#include <Box2D/Box2D.h>

class World;

class Player : public Entity {
	private:
		b2Vec2 force;
		void setBodyParams(b2BodyDef &bodyDef, float x, float y);
		void setShapeParams(b2PolygonShape &polygonShape,
                      		float width, float height);
		void setFixtureParams(const b2PolygonShape &polygonShape, 
							  b2FixtureDef &fixtureDef);

		Player(const Player &other) = delete;
		Player& operator=(const Player &other) = delete;
		Player& operator=(Player &&other) = delete;

	public:
		Player(World &world, 
               float x, float y,
               float width, float height);
		Player(Player &&other);
		~Player();
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
