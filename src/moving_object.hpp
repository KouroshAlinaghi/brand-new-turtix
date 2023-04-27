#ifndef MOVING_OBJECT_HPP
#define MOVING_OBJECT_HPP

#include "object.hpp"

class MovingObject : public Object {
protected:
    int current_texture, num_of_frames;
    bool is_moving_right, was_moving_right;
    std::vector<sf::Texture*> textures;
public:
    MovingObject(int x, int y, int width, int height, std::string texture_path, int textures);
    void draw(sf::RenderWindow& window);
    void increase_y(int value);
    void increase_x(int value);
    void handle_collision(DIR dir, Object* obj, int distance);
    virtual void handle_edge();
    void handle_fall();
    void set_is_moving_right(bool is_moving_right_);
};

#endif