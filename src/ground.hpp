#ifndef GROUND_HPP
#define GROUND_HPP

#include "stable_object.hpp"

class Ground : public StableObject {
public:
    Ground(int x, int y, int num_of_blocks);
    ENTITIES what_are_you();
};

#endif