#ifndef _OBSTACLE_H_
#define _OBSTACLE_H_

#include <Box2D/Box2D.h>
class World;

class Obstacle {
	private:
		b2Body *body;
		void setBodyParams(b2BodyDef &bodyDef, float x, float y);
		void createBody(World &world, b2BodyDef &bodyDef);
		void setShapeParams(b2PolygonShape &polygonShape,
                      		  float width, float height);
		void bindFixtureToBody(const b2PolygonShape &polygonShape);

		Obstacle(const Obstacle &other) = delete;
		Obstacle& operator=(const Obstacle &other) = delete;
		Obstacle& operator=(Obstacle &&other) = delete;

	public:
		Obstacle(World &world, 
				 float x, float y,
				 float width, float height);
		Obstacle(Obstacle &&other);
		~Obstacle();
		float getPosition_x() const;
		float getPosition_y() const;
		float getAngle() const;
};

#endif // _OBSTACLE_H_
