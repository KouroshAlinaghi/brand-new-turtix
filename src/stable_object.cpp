#include "stable_object.hpp"

StableObject::StableObject(int x_, int y_, int width, int height, std::string texture_path) : Object(x_, y_, width, height, texture_path) {
    texture.loadFromFile("statics/sprites/" + texture_path + "/pic.png");
    texture.setRepeated(true);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, width, height));
}

void StableObject::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}