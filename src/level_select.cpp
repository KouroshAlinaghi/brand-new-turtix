#include <SFML/Graphics.hpp>
#include <experimental/filesystem>
#include <iostream>

#include "level_select.hpp"

void LevelSelect::render(sf::RenderWindow& window) {
    window.clear(sf::Color::Black);
    for (auto& item : items)
        item->render(window);

    window.display();
};

void LevelSelect::tick() {}

LevelSelect::LevelSelect() : Display() {
    items.push_back(new MenuItem("Back", sf::Vector2f(100, 0), sf::Vector2f(400, 100), sf::Color::White, sf::Color::Green, sf::Color::Blue, ACTION::MAIN_MENU, &font));
    for (auto& p : std::experimental::filesystem::directory_iterator("maps")) 
        levels.push_back(new Level(p.path().string()));

    std::string name;
    for (int i = 0; i < levels.size(); i++) {
        name = "Play Level " + std::to_string(i + 1);
        items.push_back(new MenuItem(name, sf::Vector2f(100, (i+1)*100), sf::Vector2f(400, 100), sf::Color::White, sf::Color::Green, sf::Color::Blue, ACTION::GAMEPLAY, &font));
    }
    
    items.front()->select();
}

void LevelSelect::handle_event(EventQueue queue, Universe* universe) {
    Display::handle_event(queue, universe);
    for (auto event : queue) {
        if (event.first != EVENT_TYPE::KEY_PRESSED) continue;
        if (event.second == sf::Keyboard::Enter) {
            for (int i = 0; i < items.size(); i++) {
                if (items[i]->is_selected()) {
                    universe->set_current_display(items[i]->get_action());
                    if (items[i]->get_action() == ACTION::GAMEPLAY)
                        universe->set_current_level(levels[i-1]);
                }
            }
        }
        if (event.second == sf::Keyboard::Up) {
            for (int i = 0; i < items.size(); i++) {
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
            for (int i = 0; i < items.size(); i++) {
                if (items[i]->is_selected()) {
                    items[i]->unselect();
                    if (i == items.size() - 1)
                        items.front()->select();
                    else
                        items[i + 1]->select();
                    break;
                }
            }
        }
    }
}