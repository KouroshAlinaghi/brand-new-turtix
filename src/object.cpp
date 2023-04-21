#include <SFML/Graphics.hpp>
#include <iostream>

#include "object.hpp"

using namespace std;
using namespace sf;

Object::Object(int x, int y, int width, int height, std::string texture_path) {
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