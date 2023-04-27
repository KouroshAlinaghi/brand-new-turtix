#ifndef MENUITEM_HPP
#define MENUITEM_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "actions.hpp"

const sf::Color SELECTED_COLOR = sf::Color::White;
const sf::Color UNSELECTED_COLOR = sf::Color::Black;

class MenuItem {
private:
    sf::Text text;
    bool selected;
    ACTION action;
public:
    MenuItem(
            std::string text_,
            sf::Vector2f position_,
            ACTION action,
            sf::Font* font_
        );
    void render(sf::RenderWindow& window);
    void select();
    void unselect();
    bool is_selected();
    ACTION get_action();
};

#endif