#ifndef _ANIMATION_H_
#define _ANIMATION_H_

#define FRAME_RATE 1000000/25

#include "Image.h"
class Area;

class Animation {
   private:
      const Image &image;
      int rows;
      int columns;
      int currentRow;
      int currentColumn;
      bool inverseOrder;
      int width;
      int height;
      float elapsed;

      Animation(const Animation &other) = delete;
      Animation& operator=(const Animation &other) = delete;
      Animation& operator=(Animation &&other) = delete;
      void advanceDefaultOrder();
      void advanceInverseOrder();
      void advanceFrame();
   
   public:
      Animation(const Image &image, int rows, int columns,
                int width, int height, bool inverseOrder);
      Animation(Animation &&other);
      virtual ~Animation();
      virtual void update(float dt);
      virtual void render(const Area &dst, int angle, const SDL_RendererFlip &flipType);
};

#endif  // _ANIMATION_H_
