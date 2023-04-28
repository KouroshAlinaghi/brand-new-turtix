#include "turtlack.hpp"

Turtlack::Turtlack(int x_, int y_) :  MovingObject(x_, y_, 35, 48, "turtlack", 4) {
    this->shell_texture.loadFromFile("statics/sprites/turtlack/shield.png");
    this->shell.setTexture(this->shell_texture);
    this->shell.setTextureRect(sf::IntRect(0, 0, 60, 60));
    shell.setPosition(x_ - 13, y_ + 7);
    this->saved = false;
    this->freed = false;
}

ENTITIES Turtlack::what_are_you() {
    return TURTLACK;
}

bool Turtlack::is_saved() {
    return this->saved;
}

void Turtlack::handle_collision(DIR dir, Object* obj, int distance) {
    if (saved) return;
    switch (obj->what_are_you()) {
        case GROUND:
            if (dir == DOWN) {
                this->set_ay(0);
                this->set_vy(0);
                this->increase_y(-1*distance);
            } else if (dir == LEFT) {
                this->set_vx(-1*vx);
                this->set_is_moving_right(true);
                this->increase_x(distance);
            } else if (dir == RIGHT) {
                this->set_vx(-1*vx);
                this->increase_x(-1*distance);
                this->set_is_moving_right(false);
            }
            break;
        case TURTIX:
            if (dir == UP) {
                freed = true;
                vx = CONSTANT_VX;
            }
            break;
        case PORTAL: {
            saved = true;
        }
    }
}

void Turtlack::draw(sf::RenderWindow& window) {
    if (saved) return;
    if (!freed)
        window.draw(shell);
    MovingObject::draw(window);
}