#include <SFML/Graphics.hpp>
#include <iostream>

#include "moving_object.hpp"
#include "gameplay.hpp"

MovingObject::MovingObject(int x_, int y_, int width_, int height_, std::string texture_path, int textures_count) : Object(x_, y_, width_, height_, texture_path) {
    this->num_of_frames = textures_count;
    this->current_texture = num_of_frames-1;
    this->is_moving_right = true;
    this->was_moving_right = true;

    for (int i=1; i<=textures_count; i++) {
        sf::Texture* t = new sf::Texture;
        t->loadFromFile("statics/sprites/" + texture_path + "/" + std::to_string(i) + ".png");
        t->setRepeated(true);
        this->textures.push_back(t);
    }

    sprite.setTexture(*this->textures[this->current_texture]);
    sprite.setTextureRect(sf::IntRect(0, 0, width_, height_));
}

void MovingObject::handle_fall() {
    this->set_ay(GRAVITY);
}

void MovingObject::set_is_moving_right(bool is_moving_right_) {
    this->is_moving_right = is_moving_right_;
}

void MovingObject::draw(sf::RenderWindow& window) {
    if (!frame) {
        current_texture = vx == 0 ? this->num_of_frames-1 : (current_texture+1) % (this->num_of_frames-1);
        sprite.setTexture(*this->textures[current_texture]);
        if (is_moving_right) {
            sprite.setTextureRect(sf::IntRect(0, 0, width, height));
        } else {
            sprite.setTextureRect(sf::IntRect(width, 0, -1*width, height));
        }
    }
    was_moving_right = is_moving_right;
    window.draw(sprite);
}

void MovingObject::handle_edge() {}

void MovingObject::increase_x(int value) {
    x+=value;
}

void MovingObject::increase_y(int value) {
    y+=value;
}

void MovingObject::handle_collision(DIR dir, Object* obj, int distance) {
    if (obj->is_stopper())
        if (dir == UP) {
            this->set_vy(0);
            this->increase_y(distance);
        } else if (dir == DOWN) {
            this->set_ay(0);
            this->set_vy(0);
            this->increase_y(-1*distance);
        } else if (dir == LEFT) {
            if (this->what_are_you() == TURTIX) this->set_vx(0);
            this->increase_x(distance);
        } else if (dir == RIGHT) {
            if (this->what_are_you() == TURTIX) this->set_vx(0);
            this->increase_x(-1*distance);
        }
}