#include "stable_object.hpp"

class Ladder : public StableObject {
public:
    Ladder(int x, int y);
    ENTITIES what_are_you();
};