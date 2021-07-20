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
    setWeaponsPositions();
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

void PhysicalMapFactory::setTerroristsPositions() {
    YAML::Node terrorists = map["terrorist"];
    float x = 0;
    float y = 0;

    for (unsigned int i = 0; i < terrorists.size(); i++) {
        x = terrorists[i][0].as<float>() - width/2;
        y = terrorists[i][1].as<float>() - height/2;
        game.addTerroristPosition(x, y);
    }
}

void PhysicalMapFactory::setCounterTerroristsPositions() {
    YAML::Node counterTerrorists = map["counter-terrorist"];
    float x = 0;
    float y = 0;

    for (unsigned int i = 0; i < counterTerrorists.size(); i++) {
        x = counterTerrorists[i][0].as<float>()- width/2;
        y = counterTerrorists[i][1].as<float>()- height/2;
        game.addCounterTerroristPosition(x,y);
    }
}

void PhysicalMapFactory::setWeaponsPositions() {
    YAML::Node weapons = map["weapon"];
    float x = 0;
    float y = 0;
    int id = 0;

    for (unsigned int i = 0; i < weapons.size(); i++) {
        x = weapons[i][0].as<float>() - width/2;
        y = weapons[i][1].as<float>() - height/2;
        id = weapons[i][2].as<int>();
        game.addWeaponPosition(x, y, id);
    }    
}

int PhysicalMapFactory::getHeight(){
    return height + 1;
}
int PhysicalMapFactory::getWidth(){
    return width;
}
