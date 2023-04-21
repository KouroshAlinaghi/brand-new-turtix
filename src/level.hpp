#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "game_map.hpp"

class Level {
private:
    GameMap level_map;
    int score;
public:
    Level() {
        score = 0;
        level_map = GameMap();
    }
    void start();
    void terminate();
};

#endif