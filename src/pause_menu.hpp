#ifndef PAUSE_MENU_HPP
#define PAUSE_MENU_HPP

#include <SFML/Graphics.hpp>

#include "universe.hpp"
#include "display.hpp"

class PauseMenu : public Display {
public:
    PauseMenu();
    void render(sf::RenderWindow& window);
    void handle_event(EventQueue queue, Universe* universe);
    void tick(Universe* universe);
};

#endif