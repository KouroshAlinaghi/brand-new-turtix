#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP

#include <SFML/Graphics.hpp>

#include "universe.hpp"
#include "level.hpp"
#include "display.hpp"

class Gameplay : public Display {
private:
    Level* level;
public:
    void render(sf::RenderWindow& window);
    void handle_event(sf::RenderWindow& window, Universe* universe);
    void tick();
    Gameplay();
};

#endif