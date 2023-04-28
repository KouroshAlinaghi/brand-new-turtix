#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <SFML/Graphics.hpp>

#include "actions.hpp"

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
const double CONSTANT_VX = 5.9;
const double INITIAL_VY = -22.4;

enum STATE {
    STOPPED,
    MOVING_RIGHT,
    MOVING_LEFT
};

class Object {
protected:
    int x, y, width, height;
    double vx, vy, ay;
    sf::Sprite sprite;
public:
    Object(int x, int y, int width, int height, std::string texture_path);
    void set_vx(double vx);
    void set_vy(double vy);
    void set_ay(double ay);
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual void tick();
    virtual void handle_collision(DIR dir, Object* obj, int distance);
    virtual void handle_fall();
    virtual void handle_edge();
    virtual void decrease_lives();
    int get_x();
    int get_y();
    double get_vx();
    int get_height();
    int get_width();
    sf::FloatRect get_bounding_box();
    sf::Vector2f get_position();
    virtual ENTITIES what_are_you() = 0;
    void decrease_y();
    void decrease_x();
    void increase_y();
    void increase_x();
    virtual void set_is_moving_right(bool is_moving_right);
    virtual bool is_taken();
    virtual int get_value();
    bool is_stopper();
    virtual bool is_saved();
    virtual bool is_dead();
};

#endif