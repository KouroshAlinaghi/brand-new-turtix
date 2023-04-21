#ifndef GAME_MAP_HPP
#define GAME_MAP_HPP

#include <vector>

#include "object.hpp"

class GameMap {
private:
    std::vector<Object> objects;
public:
    GameMap();
    void add_object(Object object);
    void remove_object(Object object);
    void notify_collision();
    void notify_fall();
    void notify_edge();
    std::vector<Object> get_objects();
};

#endif