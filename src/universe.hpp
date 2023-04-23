#ifndef UNIVERSE_HPP
#define UNIVERSE_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <map>

#include "actions.hpp"
#include "display.hpp"
#include "level.hpp"
#include "settings.hpp"

#include "settings_display.hpp"
#include "credits.hpp"
#include "gameplay.hpp"
#include "menu.hpp"
#include "loading_screen.hpp"
#include "pause_menu.hpp"
#include "level_select.hpp"

class Universe {
private:
    sf::RenderWindow window;
    std::vector<Level> levels;
    std::map<ACTION, Display*> displays;
    Display* current_display;
    Settings settings;
    EventQueue queue;
public:
    Universe();
    void initialize_displays(Display* loading_screen);
    void start();
    void set_current_display(ACTION page);
    void close_window();
    Settings* get_settings();
    void set_current_level(Level* level);
    Display* initialize_loading_screen();
};

#endif
