#include <SFML/Graphics.hpp>
#include <experimental/filesystem>
#include <iostream>

#include "object.hpp"

using namespace std;
using namespace sf;

Object::Object(int x_, int y_, int width_, int height_, std::string texture_path) {
    this->width = width_;
    this->height = height_;
    this->vx = 0;
    this->vy = 0;
    this->ay = 0;
    this->x = x_;
    this->y = y_;
    sprite.setPosition(x_, y_);
}

int Object::get_x() {
    return x;
}

int Object::get_y() {
    return y;
}

void Object::set_is_moving_right(bool is_moving_right_) {}

void Object::tick() {
    x += vx;
    y += vy;
    vy += ay;
    sprite.setPosition(x, y);
}

sf::FloatRect Object::get_bounding_box() {
    return sprite.getGlobalBounds();
}

int Object::get_height() {
    return height;
}

int Object::get_width() {
    return width;
}

void Object::handle_collision(DIR, Object*, int) {}
void Object::handle_fall() {}
void Object::handle_edge() {}

void Object::set_vx(double vx_) {
    this->vx = vx_;
}

void Object::set_vy(double vy_) {
    this->vy = vy_;
}

void Object::set_ay(double ay_) {
    this->ay = ay_;
}

sf::Vector2f Object::get_position() {
    return sprite.getPosition();
}

bool Object::is_taken() { return false; }
int Object::get_value() { return 0; }