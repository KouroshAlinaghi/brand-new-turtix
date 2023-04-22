#include "settings.hpp"

void Settings::toggle_music() {
    music = !music;
}

void Settings::toggle_sound() {
    sound = !sound;
}

Settings::Settings() {
    width = 1080;
    height = 1920;
    fps = 60;
    volume = 100;
    fullscreen = false;
    sound = true;
    music = true;
    
    gravity = 0.5;
    constant_x_velocity = 0.5;
    initial_y_velocity = 0.5;
}