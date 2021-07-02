#include "CollisionManager.h"
#include "Entity.h"
#include <iostream>

CollisionManager::CollisionManager() { }

CollisionManager::~CollisionManager() { }

void CollisionManager::BeginContact(b2Contact *contact) {
	Entity *entityA = static_cast<Entity*>
					  (contact->GetFixtureA()->GetBody()->GetUserData());

	Entity *entityB = static_cast<Entity*>
			 		  (contact->GetFixtureB()->GetBody()->GetUserData());
	if (entityA != nullptr || entityB != nullptr) {
		entityA->collideWith(*entityB);
		entityB->collideWith(*entityA);
	}
}
