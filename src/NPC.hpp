#ifndef NPC_HPP
#define NPC_HPP

#include "moving_object.hpp"

class NPC : public MovingObject {
public:
    NPC(int x, int y, int width, int height, std::string texture_path);
};

#endif