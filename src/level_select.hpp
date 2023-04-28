#ifndef LEVEL_SELECT_HPP
#define LEVEL_SELECT_HPP

#include <SFML/Graphics.hpp>
#include <vector>

#include "universe.hpp"
#include "level.hpp"
#include "display.hpp"

class LevelSelect : public Display {
private:
    std::vector<Level*> levels;
public:
    void render(sf::RenderWindow& window);
    void handle_event(EventQueue queue, Universe* universe);
    void tick(Universe* universe);
    LevelSelect();
};

#endif