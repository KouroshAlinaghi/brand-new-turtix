#include <SFML/Graphics.hpp>
#include "turtix.hpp"
#include "events.hpp"

#include <iostream>

vector<int> ZARIBS {1, 1, 1, -1};

using namespace std;

void Turtix::tick() {
    vy += ay * 2.0;
    x += vx * 2.0;
    y += vy * 2.0;
    if (y >= 500) {
        is_already_jumping = false;
        ay = vy = 0;
    }

    sprite.setPosition(x, y);
}

void Turtix::draw(sf::RenderWindow& window) {
    if (!texture.loadFromFile("./statics/turtle.png"))
        return;
        
    sprite.setTexture(texture);
    window.draw(sprite);
}

void Turtix::handle_event(EVENT_TYPES event, DIRS dir) {
    if (dir == LEFT or dir == RIGHT) {
        if (event == KEY_PRESSED) {
            vx = X_VOLACITY * ZARIBS[dir];
        } else vx = 0;
    }

    if (dir == UP && event == KEY_PRESSED && !is_already_jumping) {
        is_already_jumping = true;
        ay = 0.03;
        vy = -2.8;
    }
}