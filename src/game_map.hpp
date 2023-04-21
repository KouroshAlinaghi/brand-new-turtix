#ifndef GAME_MAP_HPP
#define GAME_MAP_HPP

#include <SFML/Graphics.hpp>
#include <vector>

#include "object.hpp"
#include "playable.hpp"

enum DIR {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class GameMap {
private:
    std::vector<Object*> objects;
    Playable* player;
public:
    GameMap();
    void notify_collision();
    void notify_fall();
    void notify_edge();
    std::vector<Object*> get_objects();
    std::pair<int, int> get_player_position();
    void move_player(DIR dir);
    void stop_player_horizontally();
};

#endif