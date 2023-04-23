#include <SFML/Graphics.hpp>
#include <iostream>

#include "object.hpp"

using namespace std;
using namespace sf;

Object::Object(int x_, int y_, int width, int height, std::string texture_path) {
    this->vx = 0;
    this->vy = 0;
    this->ay = 0;
    this->x = x_;
    this->y = y_;
    sprite.setPosition(x_, y_);
    sprite.setTextureRect(IntRect(0, 0, width, height));
    if (!texture.loadFromFile("statics/sprites/" + texture_path))
        return;
    
    texture.setRepeated(true);
    sprite.setTexture(texture);
}

void Object::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

int Object::get_x() {
    return x;
}

int Object::get_y() {
    return y;
}

void Object::tick() {
    x += vx;
    y += vy;
    vy += ay;
    sprite.setPosition(x, y);
}

sf::FloatRect Object::get_bounding_box() {
    return sprite.getGlobalBounds();
}

void Object::handle_collision(DIR dir, Object* obj2, int distance) {}

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