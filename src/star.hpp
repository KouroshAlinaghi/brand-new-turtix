#include "stable_object.hpp"

class Star : public StableObject {
public:
    Star(int x, int y);
    ENTITIES what_are_you();
};