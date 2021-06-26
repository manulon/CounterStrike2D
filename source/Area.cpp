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

void Area::setX(int new_var) {
	x = new_var;
}
void Area::setY(int new_var) {
	y = new_var;
}

void Area::setWidth(int new_var) {
	width = new_var;
}
void Area::setHeight(int new_var) {
	height = new_var;
}
