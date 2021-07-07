#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Entity.h"
#include "Life.h"
#include <Box2D/Box2D.h>

class World;
class PrimaryWeapon;
class TertiaryWeapon;

class Player : public Entity {
	private:
		b2BodyDef bodyDef;
    	b2PolygonShape polygonShape;
    	b2FixtureDef fixtureDef;

		b2Vec2 force;
		Life life;
		
		//std::unique_ptr<SWeapon> weapon;
		SWeapon *currentWeapon;
		std::unique_ptr<SWeapon> primaryWeapon;
		//std::unique_ptr<SWeapon> secondaryWeapon;
		std::unique_ptr<SWeapon> tertiaryWeapon;


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
		void setCurrentWeapon(SWeapon *weapon);

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
		void attack(float angle);
		void reload(size_t &ammunition);
		//void setWeapon(std::unique_ptr<SWeapon> &&other);
		friend std::ostream& operator<<(std::ostream &os, const Entity &entity);
		void swapAndDropPrimaryWeapon(PrimaryWeapon &other);
		void swapAndDropTertiaryWeapon(TertiaryWeapon &other);
		void setPrimaryWeapon(std::unique_ptr<PrimaryWeapon> &&other);
		void setTertiaryWeapon(std::unique_ptr<TertiaryWeapon> &&other);
};

#endif // _PLAYER_H_
