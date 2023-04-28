#ifndef SHIELDED_HPP
#define SHIELDED_HPP

#include "enemy.hpp"

const int SHIELD_TIME_IN_SECS = 7;

class Shielded : public Enemy {
private:
    sf::Sprite shield;
    sf::Time since_last_toggle;
    bool shielded;
    sf::Clock clock;
    sf::Texture shield_texture;
public:
    Shielded(int x, int y);
    void draw(sf::RenderWindow& window);
    void tick();
    ENTITIES what_are_you();
    void handle_collision(DIR dir, Object* obj, int distance);
    void toggle_shield();
};

#endif