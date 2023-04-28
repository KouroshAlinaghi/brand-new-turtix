#include "turtix.hpp"
#include "gameplay.hpp"

#include <iostream>

Turtix::Turtix(int x_, int y_) : MovingObject(x_, y_, 51, 51, "turtle", 5) {
    this->ghost_mode = false;
    this->remained_lives = PLAYER_LIVES;
    this->points = 0;
    this->current_jumps_count = 0;
}

bool Turtix::can_jump() {
    return this->current_jumps_count < MAX_JUMPS;
}

ENTITIES Turtix::what_are_you() {
    return TURTIX;
}

void Turtix::increase_jump_count() {
    this->current_jumps_count++;
}

void Turtix::handle_collision(DIR dir, Object* obj, int distance) {
    if (obj->what_are_you() == STAR || obj->what_are_you() == DIAMOND)
        if (!obj->is_taken()) {
            points += obj->get_value();
        }

    if ((obj->what_are_you() == SHIELDED_ENEMY or obj->what_are_you() == DUMMY_ENEMY) and dir != DOWN) {
        if (this->is_ghost_mode()) return;
        if (obj->is_dead()) return;
        this->decrease_lives();
        this->ghost_mode = true;
        clock.restart();
    }

    if (obj->what_are_you() == GROUND and dir == DOWN) {
        this->current_jumps_count = 0;
    }

    MovingObject::handle_collision(dir, obj, distance);
}

int Turtix::get_lives() {
    return this->remained_lives;
}

void Turtix::tick() {
    this->when_ghost = clock.getElapsedTime();
    if (when_ghost.asSeconds() >= GHOST_TIME) {
        this->ghost_mode = false;;
    }

    MovingObject::tick();
}

int Turtix::get_points() {
    return this->points;
}

void Turtix::decrease_lives() {
    remained_lives--;
}

bool Turtix::is_ghost_mode() {
    return this->ghost_mode;
}

double Turtix::get_ghost_mode_time() {
    return clock.getElapsedTime().asSeconds();
}

bool Turtix::is_dead() {
    return !remained_lives;
}