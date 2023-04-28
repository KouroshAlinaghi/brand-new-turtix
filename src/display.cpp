#include <SFML/Graphics.hpp>
#include <iostream>

#include "universe.hpp"
#include "display.hpp"

Display::Display() {
    bg_image.loadFromFile("./statics/sprites/BG.png");
    bg_texture.loadFromImage(bg_image);
    bg_texture.setRepeated(true);
    bg_sprite.setTexture(bg_texture);
    bg_sprite.setTextureRect(sf::IntRect(0, 0, 3000, 2000));
    font.loadFromFile("./statics/font/font.ttf");
}

void Display::handle_event(EventQueue queue, Universe* universe) {
    for (auto event : queue) {
        if (event.first == EVENT_TYPE::CLOSED)
            universe->close_window();
    }
}

void Display::render(sf::RenderWindow& window) {
    window.draw(bg_sprite);
}

void Display::set_win(bool) {}