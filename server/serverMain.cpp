#include <iostream>
#include "World.h"
#include "Player.h"
#include "Obstacle.h"
#include "Bullet.h"
#include "Loader.h"
#include "FireArm.h"

int main(int argc, const char *argv[]) {
    try {
    	World world;
    	Player player(world, 
    				  0.0f, 4.0f, 
    				  1.0f, 1.0f);

    	Obstacle Obstacle(world, 
    					  30.0f, 4.0f,
    					  1.0f, 50.0f);
    	Bullet bullet(world, 0.0f, 10.0f);
    	Loader Loader(10);
        FireArm fireArm(world, 4.0f, 8.0f, 0.2f, 0.2f, 
        			    std::move(bullet), std::move(Loader));
        fireArm.shoot(-90);

        for (int32 i = 0; i < 120; ++i) {
        	world.step();
        	float position_x = player.getPositionX();
        	float position_y = player.getPositionY();
            float angle = player.getAngle();
            //printf("%4.2f %4.2f %4.2f\n", position_x, position_y, angle);

            position_x = Obstacle.getPositionX();
        	position_y = Obstacle.getPositionY();
            angle = Obstacle.getAngle();
            printf("%4.2f %4.2f %4.2f\n", position_x, position_y, angle);

            // COLOCAR ATRIBUTOS PUBLICOS
            
            position_x = fireArm.bullet.getPositionX();
        	position_y = fireArm.bullet.getPositionY();
            angle = fireArm.bullet.getAngle();
            printf("%4.2f %4.2f %4.2f\n", position_x, position_y, angle);
            

        }

    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return 1;
    }

	return 0;
}

/*
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
        	world.step();
        	float position_x = player.getPositionX();
        	float position_y = player.getPositionY();
            float angle = player.getAngle();
            //printf("%4.2f %4.2f %4.2f\n", position_x, position_y, angle);

            position_x = Obstacle.getPositionX();
        	position_y = Obstacle.getPositionY();
            angle = Obstacle.getAngle();
            printf("%4.2f %4.2f %4.2f\n", position_x, position_y, angle);

            position_x = bullet.getPositionX();
        	position_y = bullet.getPositionY();
            angle = bullet.getAngle();
            printf("%4.2f %4.2f %4.2f\n", position_x, position_y, angle);
*/