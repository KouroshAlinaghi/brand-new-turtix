#include "enemy.hpp"

#include <iostream>

Enemy::Enemy(int x_, int y_, int width_, int height_, std::string image_path, int textures) : MovingObject(x_, y_, width_, height_, image_path, textures) {
    this->set_vx(ENEMY_CONSTANT_VOLACITY);
}

void Enemy::toggle_is_moving_right() {
    is_moving_right = !is_moving_right;
}

void Enemy::handle_edge() {
    if (this->is_dead()) return;
    this->toggle_is_moving_right();
    vx *= -1;
}

bool Enemy::is_dead() {
    return !remained_lives;
}

void Enemy::decrease_lives() {
    remained_lives--;
}

void Enemy::handle_collision(DIR dir, Object* obj, int distance) {
    if (this->is_dead()) return;
    if (obj->is_stopper())
        if (dir == UP) {
            this->set_vy(0);
            this->increase_y(distance);
        } else if (dir == DOWN) {
            this->set_ay(0);
            this->set_vy(0);
            this->increase_y(-1*distance);
        } else if (dir == LEFT) {
            if (obj->what_are_you() != TURTIX and obj->what_are_you() != DIAMOND and obj->what_are_you() != STAR) {
                this->set_vx(-1 * this->get_vx());
                this->toggle_is_moving_right();
            }
            this->increase_x(distance);
        } else if (dir == RIGHT) {
            if (obj->what_are_you() != TURTIX and obj->what_are_you() != DIAMOND and obj->what_are_you() != STAR) {
                this->set_vx(-1 * this->get_vx());
                this->toggle_is_moving_right();
            }
            this->increase_x(-1*distance);
        }
}