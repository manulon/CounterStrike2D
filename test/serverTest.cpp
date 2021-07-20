#include <iostream>
#include "World.h"
#include "Player.h"
#include "Obstacle.h"
#include "Bullet.h"
#include "Loader.h"
#include "SWeapon.h"
#include "Border.h"
#include "Knife.h"
#include "Server.h"
#include "Ak47.h"
#include "SWeapon.h"

#include "Game.h"

int main(int argc, const char *argv[]) {
    try {
    Server server;
    server.run("localhost","8080");
    
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cout << "Unkown exception" << std::endl;
        return 1;
    }
	return 0;
}
