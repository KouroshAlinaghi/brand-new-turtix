#ifndef TURTIX_HPP
#define TURTIX_HPP

#include "moving_object.hpp"

const int GHOST_TIME = 3;
const int MAX_JUMPS = 2;

class Turtix : public MovingObject {
private:
    sf::Time when_ghost;
    sf::Clock clock;
    int points, remained_lives;
    bool ghost_mode;
    int current_jumps_count;
public:
    Turtix(int x, int y);
    ENTITIES what_are_you();
    void handle_collision(DIR dir, Object* obj, int distance);
    void tick();
    int get_lives();
    int get_points();
    void decrease_lives();
    bool is_ghost_mode();
    double get_ghost_mode_time();
    bool is_dead();
    bool can_jump();
    void increase_jump_count();
};

#endif