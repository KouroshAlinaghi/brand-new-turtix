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

DIR operator*(int i, DIR dir) {
    if (i == -1)
        switch (dir) {
            case DIR::UP:
                return DIR::DOWN;
            case DIR::DOWN:
                return DIR::UP;
            case DIR::LEFT:
                return DIR::RIGHT;
            case DIR::RIGHT:
                return DIR::LEFT;
        }

    return dir;
}


DIR get_direction(sf::FloatRect overlap, sf::Vector2f collision_normal, int* distance) {
    *distance = std::min(overlap.width, overlap.height);
    if (overlap.width < overlap.height) {
        if (collision_normal.x > 0) {
            return DIR::RIGHT;
        } else {
            return DIR::LEFT;
        }
    } else {
        if (collision_normal.y > 0) {
            return DIR::DOWN;
        } else {
            return DIR::UP;
        }
    }
}