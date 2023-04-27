#include "turtix.hpp"
#include "gameplay.hpp"

#include <iostream>

Turtix::Turtix(int x_, int y_) : Playable(x_, y_, 51, 51, "turtle", 5) {
    this->points = 0;
}

ENTITIES Turtix::what_are_you() {
    return TURTIX;
}

void Turtix::handle_collision(DIR dir, Object* obj, int distance) {
    if (obj->what_are_you() == STAR || obj->what_are_you() == DIAMOND)
        if (!obj->is_taken())
            points += obj->get_value();

    MovingObject::handle_collision(dir, obj, distance);
}