#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP

#include <SFML/Graphics.hpp>

#include "universe.hpp"
#include "level.hpp"
#include "display.hpp"

extern int frame;
const int FRAME_MOD = 8;
const int PLAYER_LIVES = 5;
const int VIEW_SIZE_X = 1200;
const int VIEW_SIZE_Y = 600;
const sf::Color BG_COLOR = sf::Color(140, 220, 252);
const int GHOST_MODE_TIME = 3;

class Gameplay : public Display {
private:
    Level* level;
    sf::Text points_text;
    sf::RectangleShape lives_box;
    sf::RectangleShape info_box;
    sf::Text info_text;
    std::vector<sf::Sprite*> lives;
    std::pair<sf::Texture*, sf::Texture*> lives_textures;
    void recreate_info_boxes(sf::RenderWindow& window);
    void draw_info_boxes(sf::RenderWindow& window);
    void set_view(sf::RenderWindow& window);
    std::pair<int, int> get_num_of_saved_childs_and_killed_enemies();
public:
    void render(sf::RenderWindow& window);
    void handle_event(EventQueue queue, Universe* universe);
    void tick(Universe* universe);
    Gameplay(sf::RenderWindow& window);
    void set_level(Level* level);
};

#endif