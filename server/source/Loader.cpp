#include "Loader.h"
#define RELEASE_RATE 1

Loader::Loader(size_t maxAmmunition) : 
	maxAmmunition(maxAmmunition), 
	counter(maxAmmunition) { }

Loader::Loader(Loader &&other) : 
	maxAmmunition(other.maxAmmunition), 
	counter(other.counter) {
	other.counter = 0;
}

Loader::~Loader() { }

void Loader::reload(size_t &ammunition) {
	size_t toLoad = maxAmmunition - counter;
	if (toLoad <= ammunition) {
		counter += toLoad;
		ammunition -= toLoad;
	} else {
		counter += ammunition;
		ammunition = 0;
	}
}

void Loader::releaseAmmunition() {
	if (counter >= RELEASE_RATE) {
		counter -= RELEASE_RATE;
	}
}

bool Loader::isEmpty() {
	return counter == 0 ? true : false;
}