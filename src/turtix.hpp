#include "playable.hpp"

class Turtix : public Playable {
private:
    int points; 
public:
    Turtix(int x, int y);
    ENTITIES what_are_you();
    void handle_collision(DIR dir, Object* obj, int distance);
};