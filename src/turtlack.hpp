#ifndef TURTLACK_HPP
#define TURTLACK_HPP

#include "moving_object.hpp"

class Turtlack : public MovingObject {
private:
    sf::Sprite shell;
    sf::Texture shell_texture;
    bool freed, saved;
public:
    Turtlack(int x, int y);
    ENTITIES what_are_you();
    void draw(sf::RenderWindow& window);
    void handle_collision(DIR dir, Object* obj, int distance);
    bool is_saved();
};

#endif