#include "stable_object.hpp"

class Diamond : public StableObject {
public:
    Diamond(int x, int y);
    ENTITIES what_are_you();
};