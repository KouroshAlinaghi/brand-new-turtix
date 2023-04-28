#include <SFML/Graphics.hpp>

#include "gameover.hpp"
#include "universe.hpp"

void Gameover::render(sf::RenderWindow& window) {    
    window.clear(sf::Color::Black);
    Display::render(window);
    for (auto& item : items)
        item->render(window);

    window.draw(text);
    window.display();
}

void Gameover::handle_event(EventQueue queue, Universe* universe) {
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

void Gameover::tick(Universe*) {}

Gameover::Gameover() : Display() {
    this->win = true;
    text.setFont(font);
    text.setCharacterSize(44);
    text.setFillColor(sf::Color::White);
    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(2);
    text.setPosition(sf::Vector2f(100, 100));
    items.push_back(new MenuItem("Main Menu", sf::Vector2f(100, 700), ACTION::MAIN_MENU, &font));
    items.front()->select();
}

bool Gameover::is_win() {
    return this->win;
}

void Gameover::set_win(bool win_) {
    this->win = win_;
    if (win)
        text.setString("You Win!");
    else
        text.setString("Game Over!");
}