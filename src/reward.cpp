#include "reward.hpp"

Reward::Reward(int x_, int y_, int width_, int height_, std::string texture_path) : StableObject(x_, y_, width_, height_, texture_path) {
    this->taken = false;
}

void Reward::draw(sf::RenderWindow& window) {
    if (!taken) {
        StableObject::draw(window);
    }
}

void Reward::handle_collision(DIR, Object* obj, int) {
    if (obj->what_are_you() == TURTIX)
        taken = true;
}

bool Reward::is_taken() {
    return taken;
}

int Reward::get_value() {
    return value;
}