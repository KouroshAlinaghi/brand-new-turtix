#include "enemy.hpp"

class Shielded : public Enemy {
public:
    Shielded(int x, int y);
    ENTITIES what_are_you();
};