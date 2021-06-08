#ifndef _AREA_H_
#define _AREA_H_

class Area {
	private:
		int x, y;
		int width, height;

	public:
		Area(int x, int y, int width, int height);
		int getX() const;
		int getY() const;
		int getWidth() const;
		int getHeight() const;
};

#endif // _AREA_H_
