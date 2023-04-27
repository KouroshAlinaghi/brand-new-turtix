#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "moving_object.hpp"

const int ENEMY_CONSTANT_VOLACITY = 3;

class Enemy : public MovingObject {
public:
    Enemy(int x, int y, int width, int height, std::string texture_path, int textures);
    void toggle_is_moving_right();
    void handle_edge();
};

#endif