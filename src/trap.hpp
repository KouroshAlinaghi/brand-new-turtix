#include "stable_object.hpp"

class Trap : public StableObject {
public:
    Trap(int x, int y);
    ENTITIES what_are_you();
};