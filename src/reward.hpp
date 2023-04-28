#ifndef REWARD_HPP
#define REWARD_HPP

#include <string>

#include "stable_object.hpp"

class Reward : public StableObject {
protected:
    bool taken;
    int value;
public:
    Reward(int x, int y, int width, int height, std::string texture_path);
    void draw(sf::RenderWindow& window);
    void handle_collision(DIR dir, Object* obj, int distance);
    bool is_taken();
    int get_value();
};

#endif