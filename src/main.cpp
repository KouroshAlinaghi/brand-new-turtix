#include <SFML/Graphics.hpp>
#include "turtix.hpp"
#include "events.hpp"

int main() {
    Turtix t = Turtix();
    sf::RenderWindow window(sf::VideoMode(1080, 1920), "SFML works!");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up)
                    t.handle_event(KEY_PRESSED, UP);
                if (event.key.code == sf::Keyboard::Down)
                    t.handle_event(KEY_PRESSED, DOWN);
                if (event.key.code == sf::Keyboard::Right)
                    t.handle_event(KEY_PRESSED, RIGHT);
                if (event.key.code == sf::Keyboard::Left)
                    t.handle_event(KEY_PRESSED, LEFT);
            }
            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Up)
                    t.handle_event(KEY_RELEASED, UP);
                if (event.key.code == sf::Keyboard::Down)
                    t.handle_event(KEY_RELEASED, DOWN);
                if (event.key.code == sf::Keyboard::Right)
                    t.handle_event(KEY_RELEASED, RIGHT);
                if (event.key.code == sf::Keyboard::Left)
                    t.handle_event(KEY_RELEASED, LEFT);
            }
        }

        window.clear();
        t.tick();
        t.draw(window);
        window.display();
    }

    return 0;
}
