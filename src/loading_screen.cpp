#include <SFML/Graphics.hpp>

#include "display.hpp"
#include "loading_screen.hpp"

LoadingScreen::LoadingScreen() : Display() {
    text = sf::Text("Loading...", font, 50);
    text.setPosition(100, 100);
}

void LoadingScreen::handle_event(EventQueue, Universe*) {}
void LoadingScreen::tick() {}

void LoadingScreen::render(sf::RenderWindow& window) {
    window.clear();
    window.draw(text);
    window.display();
}