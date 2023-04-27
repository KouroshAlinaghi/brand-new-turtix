#ifndef PLAYABLE_HPP
#define PLAYABLE_HPP

#include "moving_object.hpp"

class Playable : public MovingObject {
public:
    Playable(int x, int y, int width, int height, std::string texture_path, int textures);
};

#endif