#include <SFML/Graphics.hpp>
#include <iostream>

#include "object.hpp"
#include "gameplay.hpp"
#include "game_map.hpp"
#include "display.hpp"
    
const sf::Color BG_COLOR = sf::Color(140, 220, 252);
int frame = 0;

void Gameplay::render(sf::RenderWindow& window) {
    std::pair<int, int> cord = level->get_map()->get_player_position();
    view.setCenter(cord.first, cord.second);
    window.setView(view);
    window.clear(BG_COLOR);
    for (auto obj : level->get_map()->get_objects())
        obj->draw(window);

    window.display();
}

void Gameplay::tick() {
    frame = (frame + 1) % FRAME_MOD;

    for (auto obj : level->get_map()->get_objects())
        obj->tick();    

    level->get_map()->notify_collision();
    level->get_map()->notify_fall();
    level->get_map()->notify_edge();
}

void Gameplay::handle_event(EventQueue queue, Universe* universe) {
    Display::handle_event(queue, universe);
    for (auto event : queue) {
        if (event.first == EVENT_TYPE::KEY_PRESSED) {
            if (event.second == sf::Keyboard::Escape)
                universe->set_current_display(ACTION::PAUSE_MENU);
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
    view.setSize(1200, 600);
}

void Gameplay::set_level(Level* level) {
    this->level = level;
}