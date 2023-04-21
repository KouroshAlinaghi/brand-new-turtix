#include <SFML/Graphics.hpp>
#include <iostream>

#include "universe.hpp"
#include "display.hpp"

#define print(x) std::cout << x << std::endl

Display::Display() {
    font.loadFromFile("./statics/SF-Mono-Font/SFMono-Bold.otf");
}

void Display::handle_event(EventQueue queue, Universe* universe) {
    for (auto event : queue) {
        if (event.first == EVENT_TYPE::CLOSED)
            universe->close_window();
    }
}