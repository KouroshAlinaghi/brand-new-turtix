#include "dummy.hpp"

Dummy::Dummy(int x_, int y_) : Enemy(x_, y_, 72, 72, "dummy", 8) {
    this->remained_lives = 100;
}

ENTITIES Dummy::what_are_you() {
    return DUMMY_ENEMY;
}

void Dummy::handle_collision(DIR dir, Object* obj, int distance) {
    if (this->is_dead()) return;
    if (obj->what_are_you() == TURTIX && dir == UP)
        this->decrease_lives();

    Enemy::handle_collision(dir, obj, distance);
}

void Dummy::draw(sf::RenderWindow& window) {
    if (this->is_dead()) return;
    MovingObject::draw(window);
}