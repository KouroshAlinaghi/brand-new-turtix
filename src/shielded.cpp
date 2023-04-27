#include "shielded.hpp"

Shielded::Shielded(int x_, int y_) : Enemy(x_, y_, 81, 72, "shielded", 4) {
    shield_texture.loadFromFile("statics/sprites/shielded/shield.png");
    int shield_x = is_moving_right ? x - 10 : x - 12;
    shield.setTexture(shield_texture);
    shield.setPosition(shield_x, y_ - 20);
    shield.setTextureRect(sf::IntRect(0, 0, 100, 100));
    shielded = true;
}

void Shielded::draw(sf::RenderWindow& window) {
    MovingObject::draw(window);
    if (shielded) {
        window.draw(shield);
    }
}

ENTITIES Shielded::what_are_you() {
    return SHIELDED_ENEMY;
}

void Shielded::tick() {
    int shield_x = is_moving_right ? x - 10 : x - 12;
    if (shielded) {
        shield.setPosition(shield_x, y - 20);
    }
    MovingObject::tick();
}