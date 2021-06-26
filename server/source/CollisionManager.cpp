#include "CollisionManager.h"
#include "Entity.h"
#include <iostream>

CollisionManager::CollisionManager() { }

CollisionManager::~CollisionManager() { }

void CollisionManager::BeginContact(b2Contact *contact) {
	Entity* entity = static_cast<Entity*>
					 (contact->GetFixtureA()->GetBody()->GetUserData());

	Entity* entityB = static_cast<Entity*>
			 		  (contact->GetFixtureB()->GetBody()->GetUserData());
	entity->collideWith(*entityB);

	//entity = static_cast<Entity*>
	//		 (contact->GetFixtureB()->GetBody()->GetUserData());

//	if (entity != nullptr) {
		//std::cout << "ContactoB inicial de EntityID = " << entity->getID() << std::endl;
//	}
}

void CollisionManager::EndContact(b2Contact *contact) {
	Entity* entity = static_cast<Entity*>
					 (contact->GetFixtureA()->GetBody()->GetUserData());
	if (entity != nullptr) {
		//std::cout << "ContactoA final de EntityID = " << entity->getID() << std::endl;
	}

	entity = static_cast<Entity*>
			 (contact->GetFixtureB()->GetBody()->GetUserData());

	if (entity != nullptr) {
		//std::cout << "ContactoB final de EntityID = " << entity->getID() << std::endl;
	}
}
