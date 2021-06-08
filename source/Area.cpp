#include "Area.h"

Area::Area(int x, int y, int width, int height) 
	: x(x), y(y), width(width), height(height) { }
	
int Area::getX() const {
	return x;
}
int Area::getY() const {
	return y;
}
int Area::getWidth() const {
	return width;
}
int Area::getHeight() const {
	return height;
}
