#ifndef CREDITS_HPP
#define CREDITS_HPP

#include <SFML/Graphics.hpp>
#include <vector>

#include "display.hpp"
#include "universe.hpp"
#include "menu_item.hpp"

class Credits : public Display {
private:
    std::vector<MenuItem> items;
    sf::Text text;
public:
    Credits();
    void render(sf::RenderWindow& window);
    void handle_event(sf::RenderWindow& window, Universe* universe);
    void tick();
};

#endif