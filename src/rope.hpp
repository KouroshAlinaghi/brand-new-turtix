#include "stable_object.hpp"

class Rope : public StableObject {
public:
    Rope(int x, int y);
    ENTITIES what_are_you();
};