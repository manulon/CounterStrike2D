#ifndef _COLLISION_MANAGER_H_
#define _COLLISION_MANAGER_H_

#include <Box2D/Box2D.h>

class CollisionManager : public b2ContactListener {
	public:
		CollisionManager();
		~CollisionManager();
		void BeginContact(b2Contact *contact);
		//void EndContact(b2Contact *contact);
};

#endif // _COLLISION_MANAGER_H_
