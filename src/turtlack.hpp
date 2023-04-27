#include "NPC.hpp"

class Turtlack : public NPC {
private:
    sf::Sprite shell;
    sf::Texture shell_texture;
    bool is_freed, is_saved;
public:
    Turtlack(int x, int y);
    ENTITIES what_are_you();
    void draw(sf::RenderWindow& window);
    void handle_collision(DIR dir, Object* obj, int distance);
};