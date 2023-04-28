#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "reward.hpp"

class Diamond : public Reward {
public:
    Diamond(int x, int y);
    ENTITIES what_are_you();
};

#endif