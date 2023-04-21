#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP

#include <SFML/Graphics.hpp>

#include "universe.hpp"
#include "level.hpp"
#include "display.hpp"

class Gameplay : public Display {
private:
    sf::View view;
    Level* level;
public:
    void render(sf::RenderWindow& window);
    void handle_event(EventQueue queue, Universe* universe);
    void tick();
    Gameplay();
};

#endif