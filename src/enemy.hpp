#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "moving_object.hpp"

const int ENEMY_CONSTANT_VOLACITY = 3;

class Enemy : public MovingObject {
protected:
    int remained_lives;
public:
    Enemy(int x, int y, int width, int height, std::string texture_path, int textures);
    void toggle_is_moving_right();
    void handle_edge();
    void handle_collision(DIR dir, Object* obj, int distance);
    bool is_dead();
    void decrease_lives();
};

#endif