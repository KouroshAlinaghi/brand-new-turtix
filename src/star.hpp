#ifndef STAR_HPP
#define STAR_HPP

#include "reward.hpp"

class Star : public Reward {
    int value;
public:
    Star(int x, int y);
    ENTITIES what_are_you();
};

#endif