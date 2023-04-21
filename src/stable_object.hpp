#ifndef STABLE_OBJECT_HPP
#define STABLE_OBJECT_HPP

#include "object.hpp"

class StableObject : public Object {
public:
    StableObject(int x, int y, int width, int height, std::string texture_path);
};

#endif