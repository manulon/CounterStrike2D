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
        FireArm fireArm(world, 4.0f, 8.0f, 0.2f, 0.2f, 10);

        for (int32 i = 0; i < 120; ++i) {
            fireArm.shoot(15);
            std::cout << "-----Disparo-----" << std::endl;
        	world.step();
            if(i == 90) {
                size_t amm = 1;
                fireArm.reload(amm);
                std::cout << "-----Reloaded-----" << std::endl;
                std::cout << amm << std::endl;
            }
            std::cout << world;
        }

    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cout << "Unkown exception" << std::endl;
        return 1;
    }

	return 0;
}
