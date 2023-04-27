#include <SFML/Graphics.hpp>

#include "credits.hpp"

void Credits::render(sf::RenderWindow& window) {    
    window.clear(sf::Color::Black);
    Display::render(window);
    for (auto& item : items)
        item->render(window);

    window.draw(text);
    window.display();
}

void Credits::handle_event(EventQueue queue, Universe* universe) {
    Display::handle_event(queue, universe);
    for (auto event : queue) {
        if (event.first == EVENT_TYPE::KEY_PRESSED) {
            if (event.second == sf::Keyboard::Enter) {
                for (auto& item : items) {
                    if (item->is_selected()) {
                        switch (item->get_action()) {
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
    items.push_back(new MenuItem("Back", sf::Vector2f(100, 700), ACTION::MAIN_MENU, &font));
    items.front()->select();
    text.setFont(font);
    text.setCharacterSize(34);
    text.setFillColor(sf::Color::White);
    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(2);
    text.setString("Creators: \n\n\n\n\n\n\n\t\tKourosh and Mohammad Hossein"); 
    text.setPosition(sf::Vector2f(50, 100));   
}