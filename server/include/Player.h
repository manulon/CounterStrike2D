#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Entity.h"
#include "FireArm.h"
#include <Box2D/Box2D.h>

class World;

class Player : public Entity {
	private:
		b2Vec2 force;
		std::unique_ptr<FireArm> fireArm;
		b2BodyDef bodyDef;
    	b2PolygonShape polygonShape;
    	b2FixtureDef fixtureDef;
		float width;
		float height;

		Player(const Player &other) = delete;
		Player& operator=(const Player &other) = delete;
		Player& operator=(Player &&other) = delete;
		void setBodyParams(b2BodyDef &bodyDef, float x, float y);
		void setShapeParams(b2PolygonShape &polygonShape,
                      		float width, float height);
		void setFixtureParams(const b2PolygonShape &polygonShape, 
							  b2FixtureDef &fixtureDef);

	public:
		Player(World &world, 
               float x, float y,
               float width, float height, short id);
		Player(Player &&other);
		~Player();
		virtual void collideWith(Entity &entity) override;
		virtual void collideWithBullet(Bullet &bullet) override;
		virtual void collideWithObstacle(Obstacle &obstacle) override;
		virtual void collideWithFireArm(FireArm &fireArm) override;
		virtual void collideWithPlayer(Player &player) override;
		virtual void collideWithBorder(Border &border) override;
		virtual void collideWithKnife(Knife &knife) override;
		virtual void setBody(b2Body &body) override;
		void moveRight();
		void moveLeft();
		void moveUp();
		void moveDown();
		void stopMoveDown();
		void stopMoveUp();
		void stopMoveLeft();
		void stopMoveRight();
		void update();
		void bindFixture(b2FixtureDef &fixtureDef);
		void shoot(float angle);
		void reload(size_t &ammunition);
		void setFireArm(std::unique_ptr<FireArm> &&fireArm);
};

#endif // _PLAYER_H_
