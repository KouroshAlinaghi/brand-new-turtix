#include <SFML/Graphics.hpp>

#include "settings_display.hpp"
#include "display.hpp"

SettingsDisplay::SettingsDisplay() : Display() {
    items.push_back(new MenuItem("Back", sf::Vector2f(100, 100), MAIN_MENU, &font));
    items.push_back(new MenuItem("Music", sf::Vector2f(100, 210), SETTINGS, &font));
    items.push_back(new MenuItem("Sound", sf::Vector2f(100, 320), SETTINGS, &font));
    items.front()->select();
}

void SettingsDisplay::render(sf::RenderWindow& window) {
    window.clear(sf::Color::Black);
    Display::render(window);
    for (auto& item : items)
        item->render(window);

    window.display();
}

void SettingsDisplay::handle_event(EventQueue queue, Universe* universe) {
    Display::handle_event(queue, universe);
    for (auto event : queue) {
        if (event.first != EVENT_TYPE::KEY_PRESSED) continue;
        if (event.second == sf::Keyboard::Enter) {
            for (auto& item : items) {
                if (item->is_selected()) {
                    switch (item->get_action()) {
                        case ACTION::MAIN_MENU:
                            universe->set_current_display(ACTION::MAIN_MENU);
                            break;
                        case ACTION::TOGGLE_MUSIC:
                            universe->get_settings()->toggle_music();
                            break;
                        case ACTION::TOGGLE_SOUND:
                            universe->get_settings()->toggle_sound();
                            break;
                        default:
                            break;
                    }
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


void SettingsDisplay::tick(Universe*) {}