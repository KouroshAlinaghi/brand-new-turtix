#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <SFML/Graphics.hpp>

#include "menu_item.hpp"

class Universe;

class Display {
protected:
    std::vector<MenuItem> items;
    sf::Font font;
public:
    Display();
    virtual void render(sf::RenderWindow& window) = 0;
    virtual void handle_event(sf::RenderWindow& window, Universe* universe) = 0;
    virtual void tick() = 0;
};

#endif
