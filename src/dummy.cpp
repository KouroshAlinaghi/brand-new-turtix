#include "dummy.hpp"

Dummy::Dummy(int x, int y) : Enemy(x, y, CHAR_LENGTH_IN_PX, CHAR_LENGTH_IN_PX, "dummy.png") {}

ENTITIES Dummy::what_are_you() {
    return DUMMY_ENEMY;
}