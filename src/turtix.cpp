#include "turtix.hpp"
#include <iostream>

Turtix::Turtix(int x, int y) : Playable(x, y, CHAR_LENGTH_IN_PX, CHAR_LENGTH_IN_PX, "turtle.png") {}

ENTITIES Turtix::what_are_you() {
    return TURTIX;
}

void Turtix::increase_x(int value) {
    x+=value;
}

void Turtix::increase_y(int value) {
    y+=value;
}

void Turtix::handle_collision(DIR dir, Object* obj, int distance) {
    distance++;
    switch (obj->what_are_you()) {
        case GROUND:
            if (dir == UP) {
                this->set_vy(0);
                this->increase_y(distance);
            } else if (dir == DOWN) {
                this->set_vy(0);
                this->set_ay(0);
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