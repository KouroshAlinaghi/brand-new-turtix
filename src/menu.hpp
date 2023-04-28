#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "universe.hpp"
#include "display.hpp"
#include "menu_item.hpp"

class Menu : public Display {
public:
    void handle_event(EventQueue queue, Universe* universe);
    void render(sf::RenderWindow& window);
    void tick(Universe* universe);
    Menu();
};

#endif