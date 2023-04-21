#include "object.hpp"

class MovingObjects : public Object {
protected:
    double vx, vy;
    double ay;
public:
    void handle_edge();
    void handle_fall();
};