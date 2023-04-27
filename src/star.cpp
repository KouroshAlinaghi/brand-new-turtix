#include "star.hpp"

Star::Star(int x, int y) : Reward(x, y+20, 20, 19, "star") {
    this->value = 2;
    this->taken = false;
}

ENTITIES Star::what_are_you() {
    return STAR;
}