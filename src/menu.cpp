#include <SFML/Graphics.hpp>
#include <iostream>

#include "display.hpp"
#include "menu.hpp"

#define print(x) std::cout << x << std::endl;

void Menu::render(sf::RenderWindow& window) {
    window.clear(sf::Color::Black);
    for (auto& item : items)
        item.render(window);

    window.display();
};

Menu::Menu() : Display() {
    items.push_back(MenuItem("Play", sf::Vector2f(100, 0), sf::Vector2f(100, 100), sf::Color::White, sf::Color::Green, sf::Color::Blue, ACTION::GAMEPLAY, &font));
    items.push_back(MenuItem("Settings", sf::Vector2f(100, 100), sf::Vector2f(100, 100), sf::Color::White, sf::Color::Green, sf::Color::Blue, ACTION::SETTINGS, &font));
    items.push_back(MenuItem("Credits", sf::Vector2f(100, 200), sf::Vector2f(100, 100), sf::Color::White, sf::Color::Green, sf::Color::Blue, ACTION::CREDITS, &font));
    items.push_back(MenuItem("Exit", sf::Vector2f(100, 300), sf::Vector2f(100, 100), sf::Color::White, sf::Color::Green, sf::Color::Blue, ACTION::MAIN_MENU, &font));
    items.front().select();
}

void Menu::handle_event(EventQueue queue, Universe* universe) {
    Display::handle_event(queue, universe);
    for (auto event : queue) {
        if (event.first != EVENT_TYPE::KEY_PRESSED) continue;
        if (event.second == sf::Keyboard::Enter) {
            for (auto& item : items) {
                if (item.is_selected()) {
                    switch (item.get_action()) {
                        case ACTION::MAIN_MENU:
                            universe->close_window();
                            exit(0);
                            break;
                        default:
                            universe->set_current_display(item.get_action());
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

void Menu::tick() {}