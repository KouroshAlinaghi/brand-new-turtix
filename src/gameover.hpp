#ifndef GAMEOVER_HPP
#define GAMEOVER_HPP

#include <SFML/Graphics.hpp>

#include "display.hpp"

class Gameover : public Display {
private:
    sf::Text text;
    bool win;
public:
    Gameover();
    void render(sf::RenderWindow& window);
    void handle_event(EventQueue queue, Universe* universe);
    void tick(Universe*);
    bool is_win();
    void set_win(bool win);
};

#endif