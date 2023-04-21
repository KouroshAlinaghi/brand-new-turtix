#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <SFML/Graphics.hpp>

class Object {
protected:
    int x, y;
    double vx, vy, ay;
    sf::Sprite sprite;
    sf::Texture texture;
public:
    Object(int x, int y, int width, int height, std::string texture_path);
    void draw(sf::RenderWindow& window);
    void tick();
    void handle_collision();
    int get_x();
    int get_y();
};

#endif