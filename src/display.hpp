#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <SFML/Graphics.hpp>

#include "menu_item.hpp"
#include "actions.hpp"

class Universe;

class Display {
protected:
    sf::View view;
    std::vector<MenuItem*> items;
    sf::Font font;
    sf::Image bg_image;
    sf::Texture bg_texture;
    sf::Sprite bg_sprite;
public:
    Display();
    virtual void render(sf::RenderWindow& window) = 0;
    virtual void handle_event(EventQueue queue, Universe* universe);
    virtual void tick(Universe* universe) = 0;
    virtual void set_win(bool);
};

#endif
