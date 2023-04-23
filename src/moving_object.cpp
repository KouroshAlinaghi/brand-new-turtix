#include <SFML/Graphics.hpp>

#include "moving_object.hpp"

MovingObject::MovingObject(int x, int y, int width, int height, std::string texture_path) : Object(x, y, width, height, texture_path) {
    vx = 0;
    vy = 0;
}