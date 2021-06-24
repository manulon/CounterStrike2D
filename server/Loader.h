#ifndef _LOADER_H_
#define _LOADER_H_

#include <cstddef>

class Loader {
	private:
		const size_t maxAmmunition;
		size_t counter;

		Loader(const Loader &other) = delete;
		Loader& operator=(const Loader &other) = delete;
		Loader& operator=(Loader &&other) = delete;

	public:
		Loader(size_t maxAmmunition);
		Loader(Loader &&other);
		~Loader();
		void reload(size_t &ammunition);
		void releaseAmmunition();
		bool isEmpty();
};

#endif // _LOADER_H_
