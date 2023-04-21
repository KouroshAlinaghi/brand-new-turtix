#ifndef PAUSE_MENU_HPP
#define PAUSE_MENU_HPP

#include <SFML/Graphics.hpp>

#include "universe.hpp"
#include "display.hpp"

class PauseMenu : public Display {
public:
    void render(sf::RenderWindow& window);
    void handle_event(sf::RenderWindow& window, Universe* universe);
    void tick();
    PauseMenu();
};

#endif