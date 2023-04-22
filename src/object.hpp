#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <SFML/Graphics.hpp>

#include "game_map.hpp"

class Object {
protected:
    int x, y;
    double vx, vy, ay;
    sf::Sprite sprite;
    sf::Texture texture;
public:
    Object(int x, int y, int width, int height, std::string texture_path);
    void set_vx(double vx);
    void set_vy(double vy);
    void set_ay(double ay);
    void draw(sf::RenderWindow& window);
    void tick();
    void handle_collision(Object* obj);
    int get_x();
    int get_y();
    sf::FloatRect get_bounding_box();
};

#endif