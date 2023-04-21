#include <SFML/Graphics.hpp>

#include "settings_display.hpp"
#include "display.hpp"

SettingsDisplay::SettingsDisplay() : Display() {
    items.push_back(MenuItem("Back", sf::Vector2f(100, 0), sf::Vector2f(100, 100), sf::Color::White, sf::Color::Green, sf::Color::Blue, MAIN_MENU, &font));
    items.push_back(MenuItem("Fullscreen", sf::Vector2f(100, 100), sf::Vector2f(100, 100), sf::Color::White, sf::Color::Green, sf::Color::Blue, SETTINGS, &font));
    items.push_back(MenuItem("Resolution", sf::Vector2f(100, 200), sf::Vector2f(100, 100), sf::Color::White, sf::Color::Green, sf::Color::Blue, SETTINGS, &font));
    items.push_back(MenuItem("FPS", sf::Vector2f(100, 300), sf::Vector2f(100, 100), sf::Color::White, sf::Color::Green, sf::Color::Blue, SETTINGS, &font));
    items.push_back(MenuItem("Music", sf::Vector2f(100, 400), sf::Vector2f(100, 100), sf::Color::White, sf::Color::Green, sf::Color::Blue, SETTINGS, &font));
    items.push_back(MenuItem("Sound", sf::Vector2f(100, 500), sf::Vector2f(100, 100), sf::Color::White, sf::Color::Green, sf::Color::Blue, SETTINGS, &font));
    items.front().select();
}

void SettingsDisplay::render(sf::RenderWindow& window) {
    window.clear(sf::Color::Black);
    for (auto& item : items)
        item.render(window);

    window.display();
}

void SettingsDisplay::handle_event(EventQueue queue, Universe* universe) {
    Display::handle_event(queue, universe);
    for (auto event : queue) {
        if (event.first != EVENT_TYPE::KEY_PRESSED) continue;
        if (event.second == sf::Keyboard::Enter) {
            for (auto& item : items) {
                if (item.is_selected()) {
                    switch (item.get_action()) {
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
            for (int i = 0; i < items.size(); i++) {
                if (items[i].is_selected()) {
                    items[i].unselect();
                    if (i == 0)
                        items.back().select();
                    else
                        items[i - 1].select();
                    break;
                }
            }
        }
        if (event.second == sf::Keyboard::Down) {
            for (int i = 0; i < items.size(); i++) {
                if (items[i].is_selected()) {
                    items[i].unselect();
                    if (i == items.size() - 1)
                        items.front().select();
                    else
                        items[i + 1].select();
                    break;
                }
            }
        }
    }
}


void SettingsDisplay::tick() {}