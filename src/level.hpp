#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "game_map.hpp"

class Level {
private:
    GameMap game_map;
    int score;
public:
    Level();
    void start();
    void terminate();
    GameMap get_map();
};

#endif