#ifndef GAME_MAP_HPP
#define GAME_MAP_HPP

#include <SFML/Graphics.hpp>
#include <deque>
#include <string>

#include "actions.hpp"  
#include "turtix.hpp"

class Object;
class Playable;

const int SIDES_GROUNDS = 13;

class GameMap {
private:
    int num_of_childs;
    std::deque<Object*> objects;
    Turtix* player;
    std::string filename;
public:
    GameMap(std::string filename_);
    void notify_collision();
    void notify_fall();
    void notify_edge();
    std::deque<Object*> get_objects();
    std::pair<int, int> get_player_position();
    void move_player(DIR dir);
    void stop_player_horizontally();
    int get_player_lives();
    int get_player_points();
    bool get_player_ghost_mode();
    double get_player_ghost_mode_time();
    bool is_player_dead();
    int get_num_of_childs();
    void restart();
};

#endif