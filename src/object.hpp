#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <SFML/Graphics.hpp>

class Object {
protected:
    int x, y;
    sf::Sprite sprite;
    sf::Texture texture;
public:
    void draw(sf::RenderWindow& window);
    void tick();
    void handle_collision();
};

#endif