#include "level.hpp"

Level::Level(std::string filename) {
    score = 0;
    game_map = new GameMap(filename);
}

void Level::start() {}
void Level::terminate() {}
GameMap* Level::get_map() {
    return game_map;
}