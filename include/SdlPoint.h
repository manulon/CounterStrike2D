#ifndef _SDL_POINT_H_
#define _SDL_POINT_H_

#include <SDL2/SDL.h>

class SdlPoint {
	private:
		SDL_Point sdlPoint;
		SdlPoint(const SDL_Point &other) = delete;
		SdlPoint& operator=(const SdlPoint &other) = delete;

	public:
		SdlPoint(int x, int y);
        int getX() const;
        int getY() const;
		void setPosition(int x, int y);
		~SdlPoint();
};

#endif //_SDL_POINT_H_
