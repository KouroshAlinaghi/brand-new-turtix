#include "playable.hpp"

class Turtix : public Playable {
public:
    Turtix(int x, int y);
    ENTITIES what_are_you();
    void handle_collision(DIR dir, Object* obj, int distance);
    void increase_y(int value);
    void increase_x(int value);
};