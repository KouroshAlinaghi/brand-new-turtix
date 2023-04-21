#ifndef SETTINGS_HPP
#define SETTINGS_HPP

class Settings {
private:
    int width;
    int height;
    int fps;
    int volume;
    bool fullscreen;
    bool sound;
    bool music;
    
    double gravity;
    double constant_x_velocity;
    double initial_y_velocity;
public:
    void toggle_music();
    void toggle_sound();
};

#endif