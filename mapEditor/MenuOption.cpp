#include "MenuOption.h"
#include <iostream>

MenuOption::MenuOption(const char *path,Window &window,
					   int x, int y, int w, int h):
button(path,window),buttonArea(x,y,w,h){}

MenuOption::~MenuOption(){}