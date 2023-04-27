#include "diamond.hpp"

Diamond::Diamond(int x, int y) : Reward(x+20, y, 26, 21, "diamond") {
    this->value = 5;
    this->taken = false;
}

ENTITIES Diamond::what_are_you() {
    return DIAMOND;
}