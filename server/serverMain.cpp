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
        Player player(world, 2.0f, 8.0f, 2.0f, 2.0f);

        std::unique_ptr<FireArm> fireArm(new FireArm(world, 0.2f, 0.2f, 1));
        fireArm->earlyAttachToWorld(4.3f, 8.0f);
        world.spawnEntity(std::move(fireArm));

        std::cout << world;
        for (int32 i = 0; i < 120; ++i) {
            player.shoot(90);
            player.moveRight();
            player.update();
        	world.step();
            if(i == 90) {
                size_t amm = 1;
                player.reload(amm);
                std::cout << "-----Reloaded-----" << std::endl;
                std::cout << amm << std::endl;
            }
            std::cout << "-----Disparo-----" << std::endl;
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
