#ifndef PORTAL_HPP
#define PORTAL_HPP

#include "stable_object.hpp"

class Portal : public StableObject {
private:
    std::vector<sf::Texture*> textures;
    int current_texture, num_of_frames; 
public:
    Portal(int x, int y);
    ENTITIES what_are_you();
    void draw(sf::RenderWindow& window);
};

#endif