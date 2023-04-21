#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "moving_object.hpp"

class Enemy : public MovingObject {
public:
    Enemy(int x, int y, int width, int height, std::string texture_path);
    void move();
    void attack();
    void die();
    void update();
    void draw();
};

#endif