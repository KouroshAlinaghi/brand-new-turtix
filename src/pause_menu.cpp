#include <SFML/Graphics.hpp>
#include <iostream>

#include "pause_menu.hpp"
#include "display.hpp"

PauseMenu::PauseMenu() : Display() {
    items.push_back(new MenuItem("Resume", sf::Vector2f(300, 0), sf::Vector2f(100, 100), sf::Color::White, sf::Color::Green, sf::Color::Blue, ACTION::GAMEPLAY, &font));
    items.push_back(new MenuItem("Back To Levels", sf::Vector2f(300, 100), sf::Vector2f(100, 100), sf::Color::White, sf::Color::Green, sf::Color::Blue, ACTION::LEVEL_SELECT, &font));
    items.front()->select();
}

void PauseMenu::render(sf::RenderWindow& window) {
    window.clear(sf::Color::Black);
    for (auto& item : items)
        item->render(window);

    window.display();
}

void PauseMenu::handle_event(EventQueue queue, Universe* universe) {
    Display::handle_event(queue, universe);
    for (auto event : queue) {
        if (event.first != EVENT_TYPE::KEY_PRESSED) continue;
        if (event.second == sf::Keyboard::Enter) {
            for (int i = 0; i < (int)items.size(); i++) {
                if (items[i]->is_selected()) {
                    universe->set_current_display(items[i]->get_action());
                }
            }
        }
        if (event.second == sf::Keyboard::Up) {
            for (int i = 0; i < (int)items.size(); i++) {
                if (items[i]->is_selected()) {
                    items[i]->unselect();
                    if (i == 0)
                        items.back()->select();
                    else
                        items[i - 1]->select();
                    break;
                }
            }
        }
        if (event.second == sf::Keyboard::Down) {
            for (int i = 0; i < (int)items.size(); i++) {
                if (items[i]->is_selected()) {
                    items[i]->unselect();
                    if (i == (int)items.size() - 1)
                        items.front()->select();
                    else
                        items[i + 1]->select();
                    break;
                }
            }
        }
    }
}

void PauseMenu::tick() {}