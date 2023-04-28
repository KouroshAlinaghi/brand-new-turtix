#ifndef SETTINGS_HPP
#define SETTINGS_HPP

class Settings {
private:
    bool sound;
    bool music;
public:
    Settings();
    void toggle_music();
    void toggle_sound();
    bool enabled_music();
    bool enabled_sound();
};

#endif