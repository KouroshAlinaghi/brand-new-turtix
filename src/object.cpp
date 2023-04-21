#include <SFML/Graphics.hpp>

#include "object.hpp"

using namespace std;
using namespace sf;

void Object::draw(sf::RenderWindow& window) {
    if (!texture.loadFromFile("./statics/turtle.png"))
        return;
        
    sprite.setTexture(texture);
    window.draw(sprite);
}