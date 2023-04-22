#include <SFML/Graphics.hpp>
#include <iostream>

#include "object.hpp"
#include "gameplay.hpp"
#include "game_map.hpp"
#include "display.hpp"
    
void Gameplay::render(sf::RenderWindow& window) {
    std::pair<int, int> cord = level->get_map()->get_player_position();
    view.setCenter(cord.first, cord.second);
    window.setView(view);
    window.clear(sf::Color::Blue);
    for (auto obj : level->get_map()->get_objects())
        obj->draw(window);

    window.display();
}

void Gameplay::tick() {
    level->get_map()->notify_collision();
    
    for (auto obj : level->get_map()->get_objects())
        obj->tick();
}

void Gameplay::handle_event(EventQueue queue, Universe* universe) {
    Display::handle_event(queue, universe);
    for (auto event : queue) {
        if (event.first == EVENT_TYPE::KEY_PRESSED) {
            switch (event.second) {
                case sf::Keyboard::Up:
                    level->get_map()->move_player(DIR::UP);
                    break;
                case sf::Keyboard::Left:
                    level->get_map()->move_player(DIR::LEFT);
                    break;
                case sf::Keyboard::Right:
                    level->get_map()->move_player(DIR::RIGHT);
                    break;
                default:
                    break;
            }
        }
        if (event.first == EVENT_TYPE::KEY_RELEASED) {
            if (event.second == sf::Keyboard::Right or event.second == sf::Keyboard::Left)
                level->get_map()->stop_player_horizontally();
                
        }
    }
}

Gameplay::Gameplay() : Display() {
    level = new Level();
    view.setSize(1080.f, 1920.f);
    view.setCenter(350.f, 300.f);
}