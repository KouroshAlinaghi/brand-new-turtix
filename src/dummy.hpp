#ifndef DUMMY_HPP
#define DUMMY_HPP

#include "enemy.hpp"

class Dummy : public Enemy {
public:
    Dummy(int x, int y);
    ENTITIES what_are_you();
    void draw(sf::RenderWindow& window);
    void handle_collision(DIR dir, Object* obj, int distance);
};

#endif