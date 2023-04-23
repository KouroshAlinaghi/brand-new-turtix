#include "stable_object.hpp"

class TurningBlock : public StableObject {
public:
    TurningBlock(int x, int y);
    ENTITIES what_are_you();
};