#include <iostream>
#include "World.h"
#include "Player.h"
#include "Obstacle.h"
#include "Bullet.h"

int main(int argc, const char *argv[]) {
    try {
    	World world;
    	Player player(world, 
    				  0.0f, 4.0f, 
    				  1.0f, 1.0f);

    	Obstacle Obstacle(world, 
    					  30.0f, 4.0f,
    					  1.0f, 1.0f);
    	Bullet bullet(world, 4.0f, 4.0f);
        bullet.shoot(0);

        for (int32 i = 0; i < 120; ++i) {
            // TODO NO PUEDO MOVER EL JUGADOR COMO ANTES,
            // REACOMODAR PARA QUE APAREZCA EL MOVIMIENTO DE JUGADOR Y PROBAR
        	world.step();
        	float position_x = player.getPosition_x();
        	float position_y = player.getPosition_y();
            float angle = player.getAngle();
            //printf("%4.2f %4.2f %4.2f\n", position_x, position_y, angle);

            position_x = Obstacle.getPosition_x();
        	position_y = Obstacle.getPosition_y();
            angle = Obstacle.getAngle();
            printf("%4.2f %4.2f %4.2f\n", position_x, position_y, angle);

            position_x = bullet.getPosition_x();
        	position_y = bullet.getPosition_y();
            angle = bullet.getAngle();
            printf("%4.2f %4.2f %4.2f\n", position_x, position_y, angle);

        }

    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return 1;
    }

	return 0;
}
