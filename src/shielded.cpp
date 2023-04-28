#include <iostream>

#include "shielded.hpp"

Shielded::Shielded(int x_, int y_) : Enemy(x_, y_, 81, 72, "shielded", 4) {
    this->remained_lives = 200;
    shield_texture.loadFromFile("statics/sprites/shielded/shield.png");
    int shield_x = is_moving_right ? x - 10 : x - 12;
    shield.setTexture(shield_texture);
    shield.setPosition(shield_x, y_ - 20);
    shield.setTextureRect(sf::IntRect(0, 0, 100, 100));
    shielded = true;
}

void Shielded::draw(sf::RenderWindow& window) {
    if (this->is_dead()) return;
    MovingObject::draw(window);
    if (shielded) {
        window.draw(shield);
    }
}

ENTITIES Shielded::what_are_you() {
    return SHIELDED_ENEMY;
}

void Shielded::tick() {
    if (this->is_dead()) return;
    since_last_toggle = clock.getElapsedTime();
    if (since_last_toggle.asSeconds() >= SHIELD_TIME_IN_SECS) {
        this->toggle_shield();
        clock.restart();
    }

    int shield_x = is_moving_right ? x - 10 : x - 12;
    if (shielded) {
        shield.setPosition(shield_x, y - 20);
    }
    MovingObject::tick();
}

void Shielded::toggle_shield() {
    shielded = !shielded;
}

void Shielded::handle_collision(DIR dir, Object* obj, int distance) {
    if (this->is_dead()) return;
    if (obj->what_are_you() == TURTIX && dir == UP && !shielded)
        this->decrease_lives();

    Enemy::handle_collision(dir, obj, distance);
}