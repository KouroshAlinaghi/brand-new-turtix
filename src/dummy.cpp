#include "dummy.hpp"

Dummy::Dummy(int x_, int y_) : Enemy(x_, y_, 72, 72, "dummy", 8) {}

ENTITIES Dummy::what_are_you() {
    return DUMMY_ENEMY;
}