#include "enemy.hpp"

#include <iostream>

Enemy::Enemy(int x_, int y_, int width_, int height_, std::string image_path, int textures) : MovingObject(x_, y_, width_, height_, image_path, textures) {
    this->set_vx(ENEMY_CONSTANT_VOLACITY);
}

void Enemy::toggle_is_moving_right() {
    is_moving_right = !is_moving_right;
}

void Enemy::handle_edge() {
    this->toggle_is_moving_right();
    vx *= -1;
}