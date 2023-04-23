#include "NPC.hpp"

class MovableBlock : public NPC {
public:
    MovableBlock(int x, int y);
    ENTITIES what_are_you();
};