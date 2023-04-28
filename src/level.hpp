#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <string>

#include "game_map.hpp"

class Level {
private:
    GameMap* game_map;
public:
    Level(std::string filename);
    GameMap* get_map();
    void restart();
};

#endif