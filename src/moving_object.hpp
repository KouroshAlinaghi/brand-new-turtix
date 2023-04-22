#ifndef MOVING_OBJECT_HPP
#define MOVING_OBJECT_HPP

#include "object.hpp"

class MovingObject : public Object {
public:
    MovingObject(int x, int y, int width, int height, std::string texture_path);
    void handle_edge();
    void handle_fall();
};

#endif