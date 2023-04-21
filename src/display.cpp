#include <SFML/Graphics.hpp>
#include <iostream>

#include "display.hpp"

#define print(x) std::cout << x << std::endl

Display::Display() {
    font.loadFromFile("./statics/SF-Mono-Font/SFMono-Bold.otf");
}