#include "actions.hpp"

EVENT_TYPE get_event_type(sf::Event e) {
    switch (e.type) {
        case sf::Event::KeyPressed:
            return KEY_PRESSED;
        case sf::Event::KeyReleased:
            return KEY_RELEASED;
        case sf::Event::Closed:
            return CLOSED;
        default:
            return SOMETHING_ELSE;
    }
}

EventQueue generate_queue(sf::RenderWindow& window) {
    EventQueue res;
    sf::Event e;
    while (window.pollEvent(e))
        res.push_back(std::make_pair(get_event_type(e), e.key.code));

    return res;
}

void empty_queue(EventQueue& queue) {
    queue.clear();
}