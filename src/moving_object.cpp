#include <SFML/Graphics.hpp>
#include <iostream>

#include "moving_object.hpp"

MovingObject::MovingObject(int x, int y, int width, int height, std::string texture_path) : Object(x, y, width, height, texture_path) {
    vx = 0;
    vy = 0;
}

void MovingObject::handle_fall() {
    this->set_ay(GRAVITY);
}

void MovingObject::increase_x(int value) {
    x+=value;
}

void MovingObject::increase_y(int value) {
    y+=value;
}

void MovingObject::handle_collision(DIR dir, Object* obj, int distance) {
    switch (obj->what_are_you()) {
        case GROUND:
            if (dir == UP) {
                this->set_vy(0);
                this->increase_y(distance);
            } else if (dir == DOWN) {
                this->set_ay(0);
                this->set_vy(0);
                this->increase_y(-1*distance);
            } else if (dir == LEFT) {
                this->set_vx(0);
                this->increase_x(distance);
            } else if (dir == RIGHT) {
                this->set_vx(0);
                this->increase_x(-1*distance);
            }
            break;
        case DIAMOND:
            // do something
            break;
        case TRAP:
            // do something
            break;
        case ROPE:
            // do something
            break;
        case TURTIX:
            // do something
            break;
        default:
            break;
    }
}