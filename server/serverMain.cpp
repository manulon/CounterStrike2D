#include <iostream>
#include "World.h"
#include "Player.h"
#include "Obstacle.h"
#include "Bullet.h"
#include "Loader.h"
#include "FireArm.h"
#include "Border.h"

int main(int argc, const char *argv[]) {
    try {
    	World world;
        Border border(world, 0.0f, 0.0f, 100.0f, 100.0f);
        Bullet bullet(world, 0.0f, 10.0f);
        bullet.shoot(90);
    	//Loader loader(10);
        //FireArm fireArm(world, 4.0f, 8.0f, 0.2f, 0.2f);
        //fireArm.shoot(0);

        for (int32 i = 0; i < 120; ++i) {
        	world.step();
            std::cout << world;
        }

    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return 1;
    }

	return 0;
}
