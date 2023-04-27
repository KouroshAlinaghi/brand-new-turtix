#ifndef GAME_MAP_HPP
#define GAME_MAP_HPP

#include <SFML/Graphics.hpp>
#include <deque>

#include "actions.hpp"

class Object;
class Playable;

const int CHAR_LENGTH_IN_PX = 60;

class GameMap {
private:
    std::deque<Object*> objects;
    Playable* player;
public:
    GameMap(std::string filename);
    void notify_collision();
    void notify_fall();
    void notify_edge();
    std::deque<Object*> get_objects();
    std::pair<int, int> get_player_position();
    void move_player(DIR dir);
    void stop_player_horizontally();
};

#endif