#include "portal.hpp"

Portal::Portal(int x, int y) : StableObject(x, y, CHAR_LENGTH_IN_PX, CHAR_LENGTH_IN_PX, "portal.png") {}

ENTITIES Portal::what_are_you() {
    return PORTAL;
}