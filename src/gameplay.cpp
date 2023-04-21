#include <SFML/Graphics.hpp>

#include "gameplay.hpp"
#include "display.hpp"
    
void Gameplay::render(sf::RenderWindow& window) {
    window.clear(sf::Color::Black);
    for (auto obj : level->get_map().get_objects()) 
        obj.draw(window);

    window.display();
}
void Gameplay::handle_event(EventQueue queue, Universe* universe) {}
void Gameplay::tick() {}
Gameplay::Gameplay() : Display() {}