#include "Animation.h"
#include "Area.h"


//TODO Revisar la variable FRAME RATE.

Animation::Animation(std::string imgPath, Window &window, int rows, int columns,
                     int width, int height, bool inverseOrder) :
    image(imgPath.c_str(), window), rows(rows), columns(columns), 
    currentRow(0), currentColumn(0), inverseOrder(inverseOrder), 
    width(width), height(height), elapsed(0) { }

// Animation::Animation(Animation &&other) : 
//     image(other.image), rows(other.rows), columns(other.columns), 
//     currentRow(other.currentRow), currentColumn(other.currentColumn),
//     inverseOrder(other.inverseOrder), 
//     width(other.width), height(other.height), elapsed(other.elapsed) { 
//     other.rows = 0;
//     other.columns = 0;
//     other.currentRow = 0;
//     other.currentColumn = 0;
//     other.inverseOrder = 0;
//     other.width = 0;
//     other.height = 0;
//     other.elapsed = 0;
// }

Animation::~Animation() { }

void Animation::update(float dt) {
    elapsed += dt;
    while (elapsed > FRAME_RATE) {
        advanceFrame();
        elapsed -= FRAME_RATE;
    }
}

void Animation::render(const Area &dst, int angle, const SDL_RendererFlip &flipType) {
    Area src(width * currentColumn, height * currentRow, width, height);
    image.render(src, dst, angle, flipType);
}

void Animation::advanceDefaultOrder() {
    ++currentColumn;
    if (currentColumn == (columns - 1)) {
        ++currentRow;
        currentColumn = 0;
    }
    currentRow = currentRow % rows;
}

void Animation::advanceInverseOrder() {
    ++currentRow;
    if (currentRow == (rows - 1)) {
        ++currentColumn;
        currentRow = 0;
    }
    currentColumn = currentColumn % columns;  
}

void Animation::advanceFrame() {
    if (!inverseOrder) {
        advanceDefaultOrder();
    } else {
        advanceInverseOrder();      
    }
}
