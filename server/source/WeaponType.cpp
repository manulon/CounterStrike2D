#include "WeaponType.h"
#include <iostream>

WeaponType::WeaponType(float width, float height) :
	context(nullptr), width(width), height(height) { 
}

WeaponType::WeaponType(WeaponType &&other) : 
	context(other.context),
	width(other.width),
	height(other.height) { 
	other.context = nullptr;
	other.width = 0;
	other.height = 0;
}

WeaponType::~WeaponType() { }

void WeaponType::setContext(SWeapon *other) {
	context = other;
}

float WeaponType::getWidth() {
	return width;
}

float WeaponType::getHeight() {
	return height;
}

SWeapon* WeaponType::getContext() const {
	return context;
}
