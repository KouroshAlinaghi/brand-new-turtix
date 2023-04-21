#ifndef LOADINGSCREEN_HPP
#define LOADINGSCREEN_HPP

#include <SFML/Graphics.hpp>

#include "universe.hpp"
#include "display.hpp"

class LoadingScreen : public Display {
public:
    LoadingScreen();
    void render(sf::RenderWindow& window);
    void handle_event(sf::RenderWindow& window, Universe* universe);
    void tick();
};

#endif