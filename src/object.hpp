#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <SFML/Graphics.hpp>

#include "game_map.hpp"

enum ENTITIES {
    TURTIX,
    SHIELDED_ENEMY,
    DUMMY_ENEMY,
    TURTLACK,
    GROUND,
    TURNING_BLOCK,
    STAR,
    DIAMOND,
    LADDER,
    ROPE,
    TRAP,
    MOVABLE_BLOCK,
    PORTAL,
};

const double GRAVITY = 0.9;
const double CONSTANT_VX = 4.5;
const double INITIAL_VY = -25.4;

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
    virtual void tick();
    virtual void handle_collision(DIR dir, Object* obj, int distance);
    int get_x();
    int get_y();
    sf::FloatRect get_bounding_box();
    sf::Vector2f get_position();
    virtual ENTITIES what_are_you() = 0;
    void decrease_y();
    void decrease_x();
    void increase_y();
    void increase_x();
};

#endif