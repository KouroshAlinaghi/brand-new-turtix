#ifndef TURTIX
#define TURTIX

#include <SFML/Graphics.hpp>
#include <vector>
#include "events.hpp"

using namespace std;

class Turtix {
private:
    bool is_already_jumping;
    int x;
    int y;
    double vx;
    double vy;
    double ay;
    sf::Sprite sprite;
    sf::Texture texture;
public:
    Turtix() {
        is_already_jumping = false;
        x = y = 500;
        vx = vy = ay = 0;
    };
    void tick();
    void draw(sf::RenderWindow& window);
    void handle_event(EVENT_TYPES, DIRS);
};

#endif