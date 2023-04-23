#ifndef GAME_MAP_HPP
#define GAME_MAP_HPP

#include <SFML/Graphics.hpp>
#include <vector>

#include "actions.hpp"

class Object;
class Playable;

const int CHAR_LENGTH_IN_PX = 150;

class GameMap {
private:
    std::vector<Object*> objects;
    Playable* player;
public:
    GameMap(std::string filename);
    void notify_collision();
    void notify_edge();
    std::vector<Object*> get_objects();
    std::pair<int, int> get_player_position();
    void move_player(DIR dir);
    void stop_player_horizontally();
};

#endif