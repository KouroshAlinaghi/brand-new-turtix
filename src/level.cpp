#include "level.hpp"

Level::Level() {
    score = 0;
    game_map = new GameMap();
}

void Level::start() {}
void Level::terminate() {}
GameMap* Level::get_map() {
    return game_map;
}