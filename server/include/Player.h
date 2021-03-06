#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Entity.h"
#include "Life.h"
#include <Box2D/Box2D.h>

class World;
class PrimaryWeapon;
class SecondaryWeapon;
class TertiaryWeapon;

class Player : public Entity {
	private:
		b2BodyDef bodyDef;
    	b2PolygonShape polygonShape;
    	b2FixtureDef fixtureDef;
		b2Vec2 force;
		Life life;
		SWeapon *currentWeapon;
		std::shared_ptr<SWeapon> primaryWeapon;
		std::shared_ptr<SWeapon> secondaryWeapon;
		std::shared_ptr<SWeapon> tertiaryWeapon;
		float width;
		float height;
		bool pickingUpWeapon;
		short angle;

		Player(const Player &other) = delete;
		Player& operator=(const Player &other) = delete;
		Player& operator=(Player &&other) = delete;
		void setBodyParams(b2BodyDef &bodyDef, float x, float y);
		void setShapeParams(b2PolygonShape &polygonShape,
                      		float width, float height);
		void setFixtureParams(const b2PolygonShape &polygonShape, 
							  b2FixtureDef &fixtureDef);
		void setIfNullCurrentWeapon(SWeapon *weapon);
		void dropPrimaryWeapon();
		void dropSecondaryWeapon();
		void setPrimaryWeapon(PrimaryWeapon &other);
		void setSecondaryWeapon(SecondaryWeapon &other);

	public:
		Player(World &world, 
               float x, float y,
               float width, float height, short id);
		Player(Player &&other);
		~Player();
		virtual void collideWith(Entity &entity) override;
		virtual void collideWithBullet(Bullet &bullet) override;
		virtual void collideWithObstacle(Obstacle &obstacle) override;
		virtual void collideWithWeapon(SWeapon &weapon) override;
		virtual void collideWithPlayer(Player &player) override;
		virtual void collideWithBorder(Border &border) override;
		void setBody(b2Body &body) override;
		void moveRight();
		void moveLeft();
		void moveUp();
		void moveDown();
		void stopMoveDown();
		void stopMoveUp();
		void stopMoveLeft();
		void stopMoveRight();
		void update();
		void attack(float angle);
		void reload(size_t &ammunition);
		void swapAndDropPrimaryWeapon(PrimaryWeapon &other);
		void swapAndDropSecondaryWeapon(SecondaryWeapon &other);

		void setPrimaryWeapon(std::unique_ptr<PrimaryWeapon> &&other);
		void setSecondaryWeapon(std::unique_ptr<SecondaryWeapon> &&other);
		void setTertiaryWeapon(std::unique_ptr<TertiaryWeapon> &&other);
		void decreaseLife(int valueToDecrease);
		friend std::ostream& operator<<(std::ostream &os, const Entity &entity);
		short getLife();
		void setAngle(short newAngle);
		short getAngle();

		void pickUpWeapon();
		void stopPickingUpWeapon();
		bool isPickingUpWeapon();
		bool isDead();
		void switchWeapon(char weapon);
		short getCurrentWeapon();
};

#endif // _PLAYER_H_
