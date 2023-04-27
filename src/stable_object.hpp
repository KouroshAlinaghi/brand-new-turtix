#ifndef STABLE_OBJECT_HPP
#define STABLE_OBJECT_HPP

#include "object.hpp"

class StableObject : public Object {
protected:
    sf::Texture texture;
public:
    StableObject(int x, int y, int width, int height, std::string texture_path);
    void draw(sf::RenderWindow& window);
};

#endif