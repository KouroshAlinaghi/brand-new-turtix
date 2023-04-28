#include <SFML/Graphics.hpp>
#include <iostream>

#include "object.hpp"
#include "gameplay.hpp"
#include "game_map.hpp"
#include "display.hpp"

int frame = 0;

void Gameplay::set_view(sf::RenderWindow& window) {
    std::pair<int, int> cord = level->get_map()->get_player_position();
    view.setCenter(cord.first, cord.second);
    window.setView(view);
}

void Gameplay::render(sf::RenderWindow& window) {
    window.clear(BG_COLOR);
    this->set_view(window);
    for (auto obj : level->get_map()->get_objects())
        obj->draw(window);

    this->draw_info_boxes(window);
    window.display();
}

void Gameplay::draw_info_boxes(sf::RenderWindow& window) {
    recreate_info_boxes(window);
    lives_box.setPosition(window.mapPixelToCoords(sf::Vector2i(10, 10)));
    window.draw(lives_box);
    window.draw(points_text);
    for (auto life : lives)
        window.draw(*life);

    info_box.setPosition(window.mapPixelToCoords(sf::Vector2i(VIEW_SIZE_X-500, 10)));
    window.draw(info_box);
    window.draw(info_text);
}

void Gameplay::tick(Universe* universe) {
    frame = (frame + 1) % FRAME_MOD;

    for (auto obj : level->get_map()->get_objects())
        obj->tick();    

    if (level->get_map()->is_player_dead()) {
        universe->lose(this->level);
        return;
    }
    if (get_num_of_saved_childs_and_killed_enemies().first == level->get_map()->get_num_of_childs()) {
        universe->win(this->level);
        return;
    }

    level->get_map()->notify_collision();
    level->get_map()->notify_fall();
    level->get_map()->notify_edge();
}

void Gameplay::handle_event(EventQueue queue, Universe* universe) {
    Display::handle_event(queue, universe);
    for (auto event : queue) {
        if (event.first == EVENT_TYPE::KEY_PRESSED) {
            if (event.second == sf::Keyboard::Escape)
                universe->set_current_display(ACTION::PAUSE_MENU);
            switch (event.second) {
                case sf::Keyboard::Up:
                    level->get_map()->move_player(DIR::UP);
                    break;
                case sf::Keyboard::Left:
                    level->get_map()->move_player(DIR::LEFT);
                    break;
                case sf::Keyboard::Right:
                    level->get_map()->move_player(DIR::RIGHT);
                    break;
                default:
                    break;
            }
        }
        if (event.first == EVENT_TYPE::KEY_RELEASED) {
            if (event.second == sf::Keyboard::Right or event.second == sf::Keyboard::Left)
                level->get_map()->stop_player_horizontally();
                
        }
    }
}

Gameplay::Gameplay(sf::RenderWindow& window) : Display() {
    lives_box.setSize(sf::Vector2f(265, 80));
    lives_box.setFillColor(sf::Color::White);
    lives_box.setOutlineColor(sf::Color::Black);
    lives_box.setOutlineThickness(5);
    lives_box.setPosition(window.mapPixelToCoords(sf::Vector2i(10, 10)));
    lives_textures.first = new sf::Texture();
    lives_textures.second = new sf::Texture();
    lives_textures.first->loadFromFile("statics/sprites/fh.png");
    lives_textures.second->loadFromFile("statics/sprites/eh.png");
    points_text.setFont(font);
    points_text.setFillColor(sf::Color::Black);
    info_box.setSize(sf::Vector2f(575, 80));
    info_box.setFillColor(sf::Color::White);
    info_box.setOutlineColor(sf::Color::Black);
    info_box.setOutlineThickness(5);
    info_text.setFont(font);
    info_text.setFillColor(sf::Color::Black);

    for (int l = 0; l < PLAYER_LIVES; l++)
        lives.push_back(new sf::Sprite());
    
    view.setSize(VIEW_SIZE_X, VIEW_SIZE_Y);
}

void Gameplay::recreate_info_boxes(sf::RenderWindow& window) {
    points_text.setString("Points: " + std::to_string(level->get_map()->get_player_points()));
    points_text.setPosition(window.mapPixelToCoords(sf::Vector2i(20, 10)));
    for (int l = 0; l < PLAYER_LIVES; l++) {
        if (l < this->level->get_map()->get_player_lives())
            lives[l]->setTexture(*lives_textures.first);
        else
            lives[l]->setTexture(*lives_textures.second);
        lives[l]->setPosition(window.mapPixelToCoords(sf::Vector2i(20 + l * 60, 60)));
    }

    info_text.setPosition(window.mapPixelToCoords(sf::Vector2i(VIEW_SIZE_X-490, 10)));
    std::pair<int, int> saveds_and_killeds = get_num_of_saved_childs_and_killed_enemies();
    std::string ghost_mode = level->get_map()->get_player_ghost_mode() ? "ON" : "OFF";
    if (ghost_mode == "ON") {
        double ghost_mode_time = GHOST_MODE_TIME - level->get_map()->get_player_ghost_mode_time();
        ghost_mode += "\t : \t" + std::to_string(ghost_mode_time) + " SECS";
    }
    info_text.setString(std::to_string(saveds_and_killeds.first) + " Childs Saved, " + std::to_string(saveds_and_killeds.second) + " Enemies Killed.\n Ghost Mode: " + ghost_mode);
}

std::pair<int, int> Gameplay::get_num_of_saved_childs_and_killed_enemies() {
    int saveds = 0, killeds = 0;
    for (auto obj : this->level->get_map()->get_objects())
        if (obj->what_are_you() == TURTLACK and obj->is_saved())
            saveds++;
        else if ((obj->what_are_you() == DUMMY_ENEMY or obj->what_are_you() == SHIELDED_ENEMY) and obj->is_dead())
            killeds++;

    return std::make_pair(saveds, killeds);
}

void Gameplay::set_level(Level* level) {
    this->level = level;
}