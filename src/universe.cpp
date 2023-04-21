#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>

#include "universe.hpp"
#include "actions.hpp"
#include "display.hpp"

using namespace std;

Universe::Universe() {
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
}

void Universe::set_current_display(ACTION page) {
    current_display = displays[page];
}

Settings* Universe::get_settings() {
    return &settings;
}