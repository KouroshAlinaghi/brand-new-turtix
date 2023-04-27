#include "portal.hpp"
#include "gameplay.hpp"

Portal::Portal(int x, int y) : StableObject(x, y-55, 88, 88, "portal") {
    this->num_of_frames = 8;
    this->current_texture = num_of_frames-1;

    for (int i=1; i<=num_of_frames; i++) {
        sf::Texture* t = new sf::Texture;
        t->loadFromFile("statics/sprites/portal/" + std::to_string(i) + ".png");
        t->setRepeated(true);
        this->textures.push_back(t);
    }

    sprite.setTexture(*this->textures[this->current_texture]);
    sprite.setTextureRect(sf::IntRect(0, 0, 88, 88));
}

ENTITIES Portal::what_are_you() {
    return PORTAL;
}

void Portal::draw(sf::RenderWindow& window) {
    if (!frame) {
        current_texture = (current_texture+1) % (this->num_of_frames-1);
        sprite.setTexture(*this->textures[current_texture]);
    }
    window.draw(sprite);
}