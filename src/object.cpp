#include <SFML/Graphics.hpp>
#include <iostream>

#include "object.hpp"

using namespace std;
using namespace sf;

Object::Object(int x, int y, int width, int height, std::string texture_path) {
    this->vx = 0;
    this->vy = 0;
    this->ay = 0;
    this->x = x;
    this->y = y;
    sprite.setPosition(x, y);
    texture.loadFromFile(texture_path);
    sprite.setTextureRect(IntRect(0, 0, width, height));
    if (!texture.loadFromFile(texture_path))
        return;
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

void Object::handle_collision(Object* obj2) {
    this->set_vx(0);
    this->set_vy(0);
    this->set_ay(0);
}

void Object::set_vx(double vx) {
    this->vx = vx;
}

void Object::set_vy(double vy) {
    this->vy = vy;
}

void Object::set_ay(double ay) {
    this->ay = ay;
}