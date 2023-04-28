#include "settings.hpp"

void Settings::toggle_music() {
    music = !music;
}

void Settings::toggle_sound() {
    sound = !sound;
}

Settings::Settings() {
    sound = true;
    music = true;
}

bool Settings::enabled_music() {
    return this->music;
}

bool Settings::enabled_sound() {
    return this->sound;
}