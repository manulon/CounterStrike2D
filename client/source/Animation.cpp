#include "Animation.h"
#include "Area.h"

//TODO Revisar la variable FRAME RATE.

Animation::Animation(std::string imgPath, Window &window, int rows, int columns,
                     int width, int height, bool inverseOrder) :
    window(window), 
    terroristAk47("../assets/gfx/player/t4Ak47.png", window), 
    terroristKnife("../assets/gfx/player/t4Knife.png", window), 
    counterTerroristAk47("../assets/gfx/player/ct4Ak47.png", window), 
    counterTerroristKnife("../assets/gfx/player/ct4Knife.png", window),
    image(&counterTerroristAk47),
    rows(rows), columns(columns), currentRow(0), currentColumn(0), inverseOrder(inverseOrder), 
    width(width), height(height), elapsed(0){}

Animation::Animation(Animation &&other) : 
    window(other.window), 
    terroristAk47(std::move(other.terroristAk47)), 
    terroristKnife(std::move(other.terroristKnife)), 
    counterTerroristAk47(std::move(other.counterTerroristAk47)), 
    counterTerroristKnife(std::move(other.counterTerroristKnife)),
    image(other.image),
    rows(other.rows), columns(other.columns),
    currentRow(other.currentRow), currentColumn(other.currentColumn),
    inverseOrder(other.inverseOrder), 
    width(other.width), height(other.height), elapsed(other.elapsed) {
    other.rows = 0;
    other.columns = 0;
    other.currentRow = 0;
    other.currentColumn = 0;
    other.inverseOrder = 0;
    other.width = 0;
    other.height = 0;
    other.elapsed = 0;
}

// Animation& Animation::operator=(Animation &&other){
//     if (this ==  &other){
//         return *this;
//     }
//     image = std::move(other.image);
//     rows = other.rows;
//     columns = other.columns ;
//     currentRow = other.currentRow ;
//     currentColumn = other.currentColumn; 
//     inverseOrder = other.inverseOrder ;
//     width = other.width ;
//     height = other.height ;
//     elapsed = other.elapsed ;
    
//     other.rows = 0;
//     other.columns = 0;
//     other.currentRow = 0;
//     other.currentColumn = 0;
//     other.inverseOrder = 0;
//     other.width = 0;
//     other.height = 0;
//     other.elapsed = 0;

//     return *this;
// }

Animation::~Animation() { }

void Animation::render(const Area &dst, int angle, const SDL_RendererFlip &flipType) {
    Area src(width * currentColumn, 18, width, height);
    image->render(src, dst, angle, flipType);
}
