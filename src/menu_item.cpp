#include <SFML/Graphics.hpp>

#include "menu_item.hpp"

void MenuItem::render(sf::RenderWindow& window) {
    window.draw(text);
}

void MenuItem::select() {
    selected = true;
    text.setFillColor(SELECTED_COLOR);
    text.setOutlineColor(UNSELECTED_COLOR);
}

void MenuItem::unselect() {
    selected = false;
    text.setFillColor(UNSELECTED_COLOR);
    text.setOutlineColor(SELECTED_COLOR);
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
        ACTION action_,
        sf::Font* font
    ) {
    text.setFont(*font);
    text.setCharacterSize(30);
    text.setOutlineColor(SELECTED_COLOR);
    text.setOutlineThickness(1);
    text.setFillColor(UNSELECTED_COLOR);
    text.setString(text_);
    text.setPosition(position_);
    selected = false;
    action = action_;
}