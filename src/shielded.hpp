#include "enemy.hpp"

class Shielded : public Enemy {
private:
    sf::Sprite shield;
    bool shielded;
    sf::Texture shield_texture;
public:
    Shielded(int x, int y);
    void draw(sf::RenderWindow& window);
    void tick();
    ENTITIES what_are_you();
};