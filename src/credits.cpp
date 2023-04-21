#include <SFML/Graphics.hpp>

#include "credits.hpp"

void Credits::render(sf::RenderWindow& window) {    
    window.clear(sf::Color::Black);
    for (auto& item : items)
        item.render(window);

    window.draw(text);
    window.display();
}

void Credits::handle_event(sf::RenderWindow& window, Universe* universe) {
    sf::Event e;
    while (window.pollEvent(e)) {
        if (e.type == sf::Event::Closed)
            window.close();

        if (e.type == sf::Event::KeyPressed) {
            if (e.key.code == sf::Keyboard::Enter) {
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


            if (e.key.code == sf::Keyboard::Up) {
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
            } else if (e.key.code == sf::Keyboard::Down) {
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