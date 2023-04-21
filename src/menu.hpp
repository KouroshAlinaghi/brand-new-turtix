#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "universe.hpp"
#include "display.hpp"
#include "menu_item.hpp"

class Menu : public Display {
private:
    std::vector<MenuItem> items;
public:
    void handle_event(sf::RenderWindow& window, Universe* universe);
    void render(sf::RenderWindow& window);
    void tick();
    Menu();
};

#endif