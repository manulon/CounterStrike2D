#include "PrimaryWeapon.h"
#include "Player.h"
#include "SWeapon.h"
#include <utility>
#include <iostream>

PrimaryWeapon::PrimaryWeapon(World &world, 
							 float width, float height,
							 float maxAmmunition, short id) :
	WeaponType(width, height,id),
	world(world),
	loader(world, maxAmmunition) { } 
 
PrimaryWeapon::PrimaryWeapon(PrimaryWeapon &&other) :
	WeaponType(std::move(other)),
	world(other.world),
	loader(std::move(other.loader)) { } 

PrimaryWeapon::~PrimaryWeapon() { }

void PrimaryWeapon::collideWithPlayer(Player &player) {
	if (player.isPickingUpWeapon()){
        std::cout<<"Voy a setear el sensor en false"<<std::endl;
		context->getBody()->GetFixtureList()->SetSensor(false);
		std::cout<<"setee el sensor en false"<<std::endl;
        player.swapAndDropPrimaryWeapon(*this);
		std::cout<<"Voy a hacer el cambio"<<std::endl;
    }
	std::cout<<"Voy a setear el sensor en true"<<std::endl;
    context->getBody()->GetFixtureList()->SetSensor(true);		
	std::cout<<"setee"<<std::endl;
}
