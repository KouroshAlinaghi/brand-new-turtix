#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>

#include "universe.hpp"
#include "actions.hpp"
#include "display.hpp"

using namespace std;

Universe::Universe() {
    settings = Settings();
    window.create(sf::VideoMode(1080, 1920), "Turtix!");
    initialize_displays();
    set_current_display(ACTION::MAIN_MENU);
}

void Universe::close_window() {
    window.close();
}

void Universe::start() {
    while (window.isOpen()) {
        queue = generate_queue(window);
        current_display->handle_event(queue, this);
        empty_queue(queue);
        current_display->tick();
        current_display->render(window);
    }
}

void Universe::initialize_displays() {
    displays[ACTION::CREDITS] = new Credits();
    displays[ACTION::GAMEPLAY] = new Gameplay();
    displays[ACTION::MAIN_MENU] = new Menu();
    displays[ACTION::LOADING_SCREEN] = new LoadingScreen();
    displays[ACTION::PAUSE_MENU] = new PauseMenu();
    displays[ACTION::SETTINGS] = new SettingsDisplay();
    displays[ACTION::LEVEL_SELECT] = new LevelSelect();
}

void Universe::set_current_display(ACTION page) {
    window.setView(sf::View(sf::FloatRect(0, 0, 1000, 1000)));
    current_display = displays[page];
}

Settings* Universe::get_settings() {
    return &settings;
}

void Universe::set_current_level(Level* level) {
    ((Gameplay*)displays[ACTION::GAMEPLAY])->set_level(level);
}