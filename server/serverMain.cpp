#include <iostream>
#include "World.h"
#include "Player.h"

int main(int argc, const char *argv[]) {
    try {
    	World world;
    	Player player(world, 
    				  0.0f, 4.0f, 
    				  1.0f, 1.0f);
    	//player.moveRight();
    	/*Player player2(world, 
    				   2.0f, 1.0f, 
    				   1.0f, 1.0f);*/

        for (int32 i = 0; i < 60; ++i) {
        	player.moveRight();
        	world.step();
        	float position_x = player.getPosition_x();
        	float position_y = player.getPosition_y();
            float angle = player.getAngle();
            printf("%4.2f %4.2f %4.2f\n", position_x, position_y, angle);

            /*position_x = player2.getPosition_x();
        	position_y = player2.getPosition_y();
            angle = player2.getAngle();
            printf("%4.2f %4.2f %4.2f\n", position_x, position_y, angle);*/
        }

    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return 1;
    }

	return 0;
}
