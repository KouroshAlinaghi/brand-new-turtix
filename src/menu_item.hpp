#ifndef MENUITEM_HPP
#define MENUITEM_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "actions.hpp"

class MenuItem {
private:
    sf::Text text;
    sf::RectangleShape rect;
    sf::Color color;
    sf::Color selected_color;
    sf::Color unselected_color;
    bool selected;
    ACTION action;
public:
    MenuItem(
            std::string text_,
            sf::Vector2f position_,
            sf::Vector2f size_,
            sf::Color color_,
            sf::Color selected_color_,
            sf::Color unselected_color_,
            ACTION action,
            sf::Font* font_
        );
    void handle_event(sf::RenderWindow& window);
    void render(sf::RenderWindow& window);
    void tick();
    void select();
    void unselect();
    bool is_selected();
    ACTION get_action();
};

#endif