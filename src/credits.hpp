#ifndef CREDITS_HPP
#define CREDITS_HPP

#include <SFML/Graphics.hpp>
#include <vector>

#include "display.hpp"
#include "universe.hpp"
#include "menu_item.hpp"

class Credits : public Display {
private:
    sf::Text text;
public:
    Credits();
    void render(sf::RenderWindow& window);
    void handle_event(EventQueue queue, Universe* universe);
    void tick();
};

#endif