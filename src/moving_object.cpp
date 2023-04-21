#include <SFML/Graphics.hpp>

#include "moving_object.hpp"

using namespace std;
using namespace sf;

void Object::tick() {
    sprite.move(1, 0);
}