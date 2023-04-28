#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>

#include "universe.hpp"
#include "actions.hpp"
#include "display.hpp"

using namespace std;

Universe::Universe() {
    settings = Settings();
    window.create(sf::VideoMode(1366, 768), "Turtix!", sf::Style::Fullscreen);
    window.setFramerateLimit(60);
    Display* loading_screen = initialize_loading_screen();
    loading_screen->render(window);
    initialize_displays(loading_screen);
    set_current_display(ACTION::MAIN_MENU);
}

Display* Universe::initialize_loading_screen() {
    return new LoadingScreen();
}

void Universe::close_window() {
    window.close();
}

void Universe::start() {
    while (window.isOpen()) {
        queue = generate_queue(window);
        current_display->handle_event(queue, this);
        empty_queue(queue);
        current_display->tick(this);
        current_display->render(window);
    }
}

void Universe::initialize_displays(Display* loading_screen) {
    displays[ACTION::LOADING_SCREEN] = loading_screen;
    displays[ACTION::CREDITS] = new Credits();
    displays[ACTION::GAMEPLAY] = new Gameplay(window);
    displays[ACTION::MAIN_MENU] = new Menu();
    displays[ACTION::PAUSE_MENU] = new PauseMenu();
    displays[ACTION::SETTINGS] = new SettingsDisplay();
    displays[ACTION::LEVEL_SELECT] = new LevelSelect();
    displays[ACTION::GAMEOVER] = new Gameover();
}

void Universe::set_current_display(ACTION page) {
    window.setView(sf::View(sf::FloatRect(0, 0, 1000, 1000)));
    current_display = displays[page];
}

void Universe::lose(Level* level) {
    level->restart();
    this->displays[ACTION::GAMEOVER]->set_win(false);
    set_current_display(ACTION::GAMEOVER);
}

void Universe::win(Level* level) {
    level->restart();
    this->displays[ACTION::GAMEOVER]->set_win(true);
    set_current_display(ACTION::GAMEOVER);
}

Settings* Universe::get_settings() {
    return &settings;
}

void Universe::set_current_level(Level* level) {
    ((Gameplay*)displays[ACTION::GAMEPLAY])->set_level(level);
}