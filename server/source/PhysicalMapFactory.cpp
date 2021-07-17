#include "PhysicalMapFactory.h"
#include "Game.h"

PhysicalMapFactory::PhysicalMapFactory(World &w, std::string mapName, Game &g) : 
    world(w),
    map(YAML::LoadFile(mapName)), 
    border(createBorders()),
    game(g) {
    YAML::Node obstaclesyaml = map["obstacles"];
    
    for (unsigned int i = 0; i < obstaclesyaml.size();i++){
        YAML::Node obstacle = obstaclesyaml[i];
        std::unique_ptr<Obstacle> ptr(new Obstacle(world,
                                      obstacle[0].as<int>()-(width/2),obstacle[1].as<int>()-(height/2)
                                     ,0.45f,0.45f));
        obstacles.push_back(std::move(ptr));
    }
    setTerroristsPositions();
    setCounterTerroristsPositions();
}

Border* PhysicalMapFactory::createBorders(){
    YAML::Node obstacles = map["obstacles"];
    YAML::Node  fields = map["fields"];
    width = 0;
    height = 0;
    for (unsigned int i = 0; i <fields.size(); i++) {
        if (fields[i][0].as<int>() > width) width = fields[i][0].as<int>();
        if (fields[i][1].as<int>() > height) height = fields[i][1].as<int>();
    }
    for (unsigned int i = 0; i < obstacles.size(); i++){
        if (obstacles[i][0].as<int>() > width) width = obstacles[i][0].as<int>();
        if (obstacles[i][1].as<int>() > height) height = obstacles[i][1].as<int>();
    }
    return (new Border(world, 0,0, width + 1, height + 1));    
}

// NUEVO OJO
void PhysicalMapFactory::setTerroristsPositions() {
    YAML::Node terrorists = map["terrorists"];
    float x = 0;
    float y = 0;

    for (unsigned int i = 0; i < terrorists.size(); i++) {
        x = terrorists[i][0].as<float>();
        y = terrorists[i][1].as<float>();
        game.addTerroristPosition(x, y);
    }
}

void PhysicalMapFactory::setCounterTerroristsPositions() {
    YAML::Node counterTerrorists = map["counterTerrorists"];
    float x = 0;
    float y = 0;

    for (unsigned int i = 0; i < counterTerrorists.size(); i++) {
        x = counterTerrorists[i][0].as<float>();
        y = counterTerrorists[i][1].as<float>();
        game.addCounterTerroristPosition(x,y);
    }
}
//

int PhysicalMapFactory::getHeight(){
    return height + 1;
}
int PhysicalMapFactory::getWidth(){
    return width;
}
