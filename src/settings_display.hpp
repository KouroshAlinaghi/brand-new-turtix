#ifndef SETTINGS_DISPLAY_HPP
#define SETTINGS_DISPLAY_HPP

#include <SFML/Graphics.hpp>

#include "display.hpp"
#include "menu_item.hpp"
#include "universe.hpp"

class SettingsDisplay : public Display {
public:
    SettingsDisplay();
    void render(sf::RenderWindow& window);
    void handle_event(sf::RenderWindow& window, Universe* universe);
    void tick();
};

#endif