#include "level.hpp"

Level::Level(std::string filename) {
    game_map = new GameMap(filename);
}

GameMap* Level::get_map() {
    return game_map;
}

void Level::restart() {
    game_map->restart();
}