#ifndef ACTIONS_HPP
#define ACTIONS_HPP

#include <SFML/Graphics.hpp>

enum ACTION {
    CREDITS, GAMEPLAY, MAIN_MENU, LOADING_SCREEN, PAUSE_MENU, SETTINGS,
    TOGGLE_MUSIC, TOGGLE_SOUND
};

enum EVENT_TYPE { KEY_RELEASED, KEY_PRESSED, CLOSED, SOMETHING_ELSE };

typedef std::pair<EVENT_TYPE, sf::Keyboard::Key> KeyboardEvent;
typedef std::vector<KeyboardEvent> EventQueue;

EVENT_TYPE get_event_type(sf::Event e);
EventQueue generate_queue(sf::RenderWindow& window);
void empty_queue(EventQueue& queue);

#endif