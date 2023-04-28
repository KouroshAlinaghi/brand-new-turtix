#ifndef ACTIONS_HPP
#define ACTIONS_HPP

#include <SFML/Graphics.hpp>

enum DIR {UP, DOWN, LEFT, RIGHT};
enum EVENT_TYPE { KEY_RELEASED, KEY_PRESSED, CLOSED, SOMETHING_ELSE };
enum ACTION {
    LEVEL_SELECT, CREDITS, GAMEPLAY, MAIN_MENU, LOADING_SCREEN, PAUSE_MENU, SETTINGS, GAMEOVER,
    TOGGLE_MUSIC, TOGGLE_SOUND
};

const int CHAR_LENGTH_IN_PX = 60;

typedef std::pair<EVENT_TYPE, sf::Keyboard::Key> KeyboardEvent;
typedef std::vector<KeyboardEvent> EventQueue;

EVENT_TYPE get_event_type(sf::Event e);
EventQueue generate_queue(sf::RenderWindow& window);
void empty_queue(EventQueue& queue);
DIR operator*(int i, DIR dir);
DIR get_direction(sf::FloatRect overlap, sf::Vector2f collision_normal, int* distance);

#endif