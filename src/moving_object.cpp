#include <SFML/Graphics.hpp>

#include "moving_object.hpp"

MovingObject::MovingObject(int x, int y, int width, int height, std::string texture_path) : Object(x, y, width, height, texture_path) {
    vx = 0;
    vy = 0;
    ay = 0;
}

void MovingObject::set_vx(double vx) {
    this->vx = vx;
}

void MovingObject::set_vy(double vy) {
    this->vy = vy;
}

void MovingObject::set_ay(double ay) {
    this->ay = ay;
}