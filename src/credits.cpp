#include <SFML/Graphics.hpp>

#include "credits.hpp"

void Credits::render(sf::RenderWindow& window) {    
    window.clear(sf::Color::Black);
    for (auto& item : items)
        item.render(window);

    window.draw(text);
    window.display();
}

void Credits::handle_event(EventQueue queue, Universe* universe) {
    Display::handle_event(queue, universe);
    for (auto event : queue) {
        if (event.first == EVENT_TYPE::KEY_PRESSED) {
            if (event.second == sf::Keyboard::Enter) {
                for (auto& item : items) {
                    if (item.is_selected()) {
                        switch (item.get_action()) {
                            case ACTION::MAIN_MENU:
                                universe->set_current_display(ACTION::MAIN_MENU);
                                break;
                            default:
                                break;
                        }
                    }
                }
            }
        }
    }
}

void Credits::tick() {}

Credits::Credits() : Display() {
    items.push_back(MenuItem("Back", sf::Vector2f(100, 0), sf::Vector2f(100, 100), sf::Color::White, sf::Color::Green, sf::Color::Blue, MAIN_MENU, &font));
    items.front().select();
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setString("Creators: Kourosh and Mohammad Hossein");    
}