#ifndef _SWEAPON_H_
#define _SWEAPON_H_

#include "Entity.h"
class WeaponType;

class SWeapon : public Entity {
	private:

		void setBodyParams(b2BodyDef &bodyDef, float x, float y);
		void setShapeParams(b2PolygonShape &polygonShape,
                      		float width, float height,
                            float x, float y);
		void setFixtureParams(const b2PolygonShape &polygonShape, 
							  b2FixtureDef &fixtureDef);
		
		SWeapon(const SWeapon &other) = delete;
		SWeapon& operator=(const SWeapon &other) = delete;
		SWeapon& operator=(SWeapon &&other) = delete;

	public:
	    b2BodyDef bodyDef;
    	b2PolygonShape polygonShape;
		b2FixtureDef fixtureDef;

		std::unique_ptr<WeaponType> weaponType;
		SWeapon(World &world, std::unique_ptr<WeaponType> &&weaponType);
		SWeapon(SWeapon &&other);
		virtual ~SWeapon();

		void collideWith(Entity &entity) override;
		void collideWithBullet(Bullet &bullet) override;
		void collideWithObstacle(Obstacle &obstacle) override;
		void collideWithPlayer(Player &player) override;
		void collideWithBorder(Border &border) override;
		void collideWithWeapon(SWeapon &Weapon) override;

		void earlyAttachToWorld(float x, float y);
		void lateAttachToWorld(float x, float y);
		void attack(float angle, float x, float y);
		void reload(size_t &ammunition);
		void setBody(b2Body &body);
		bool playerIsInWeapon(int x, int y);
};

#endif // _SWEAPON_H_
