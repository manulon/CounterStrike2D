#include "Exception.h"
#include "SdlException.h"
#include <iostream>

int main() {
	Exception exception("Esto es %s de como es %c++ version %i", "prueba", 'c', 11);
	std::cout << exception.what() << std::endl;

	return 0;
}