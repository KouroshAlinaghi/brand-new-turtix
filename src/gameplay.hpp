#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP

#include <SFML/Graphics.hpp>

#include "universe.hpp"
#include "level.hpp"
#include "display.hpp"

extern int frame;
const int FRAME_MOD = 8;

class Gameplay : public Display {
private:
    Level* level;
public:
    void render(sf::RenderWindow& window);
    void handle_event(EventQueue queue, Universe* universe);
    void tick();
    Gameplay();
    void set_level(Level* level);
};

#endif