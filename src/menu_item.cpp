#include <SFML/Graphics.hpp>

#include "menu_item.hpp"

void MenuItem::render(sf::RenderWindow& window) {
    window.draw(rect);
    window.draw(text);
}

void MenuItem::select() {
    selected = true;
    rect.setFillColor(selected_color);
}

void MenuItem::unselect() {
    selected = false;
    rect.setFillColor(unselected_color);
}

bool MenuItem::is_selected() {
    return selected;
}

ACTION MenuItem::get_action() {
    return action;
}

MenuItem::MenuItem(
        std::string text_,
        sf::Vector2f position_,
        sf::Vector2f size_,
        sf::Color color_,
        sf::Color selected_color_,
        sf::Color unselected_color_,
        ACTION action_,
        sf::Font* font
    ) {
    selected_color = selected_color_;
    unselected_color = unselected_color_;
    text.setFont(*font);
    text.setCharacterSize(20);
    text.setFillColor(color_);
    text.setString(text_);
    text.setPosition(position_ + sf::Vector2f(10, 10));
    rect.setPosition(position_);
    rect.setSize(size_);
    rect.setFillColor(unselected_color);
    selected = false;
    action = action_;
}