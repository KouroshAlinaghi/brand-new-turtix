#include <vector>
#include <fstream>
#include <iostream>

#include "object.hpp"
#include "game_map.hpp"

#include "ground.hpp"
#include "diamond.hpp"
#include "portal.hpp"
#include "dummy.hpp"
#include "shielded.hpp"
#include "turtlack.hpp"
#include "star.hpp"
#include "movable_block.hpp"
#include "trap.hpp"
#include "ladder.hpp"
#include "rope.hpp"
#include "turning_block.hpp"
#include "turtix.hpp"

void GameMap::notify_collision() {
    sf::FloatRect overlap;
    int distance = 0;
    for (int i = 0; i < (int)objects.size(); i++) {
        for (int j = i + 1; j < (int)objects.size(); j++) {
            if (objects[i]->get_bounding_box().intersects(objects[j]->get_bounding_box(), overlap)) {
                DIR dir = get_direction(overlap, objects[j]->get_position() - objects[i]->get_position(), &distance);
                objects[i]->handle_collision(dir, objects[j], distance);
                objects[j]->handle_collision(-1 * dir, objects[i], distance);
            }
        }
    }
}

void GameMap::notify_edge() {}

std::vector<Object*> GameMap::get_objects() {
    return objects;
}

std::pair<int, int> GameMap::get_player_position() {
    return std::make_pair(player->get_x(), player->get_y());
}

void GameMap::move_player(DIR dir) {
    switch (dir) {
        case RIGHT:
            player->set_vx(CONSTANT_VX);
            break;
        case LEFT:
            player->set_vx(-1*CONSTANT_VX);
            break;
        case UP:
            player->set_vy(INITIAL_VY);
            player->set_ay(GRAVITY);
            break;
        default:
            break;
    }
}

void GameMap::stop_player_horizontally() {
    player->set_vx(0);
}

GameMap::GameMap(std::string filename) {
    std::ifstream file(filename);
    std::string line;
    Object* turtix;
    int current_y = 0, current_x = 0, current_grounds = 0;
    while (std::getline(file, line)) {
        current_grounds = 0;
        current_x = 0;
        for (int i = 0; i < (int)line.size(); i++) {
            if (i == (int)line.size() - 1 and line[i] == '.') {
                current_grounds++;
                objects.push_back(new Ground(current_x-CHAR_LENGTH_IN_PX*(current_grounds+1), current_y, current_grounds));
            }
            if (line[i] == '.') {
                current_grounds++;
            } else {
                if (current_grounds)
                    objects.push_back(new Ground(current_x-CHAR_LENGTH_IN_PX*(current_grounds+1), current_y, current_grounds));
                current_grounds = 0;
                switch (line[i]) {
                    case '^':
                        objects.push_back(new Diamond(current_x, current_y));
                        break;
                    case '$':
                        turtix = new Turtix(current_x + CHAR_LENGTH_IN_PX, current_y);
                        objects.push_back(new Portal(current_x, current_y));
                        objects.push_back(turtix);
                        break;
                    case 'E':
                        objects.push_back(new Dummy(current_x, current_y));
                        break;
                    case 'M':
                        objects.push_back(new Shielded(current_x, current_y));
                        break;
                    case 'O':
                        objects.push_back(new Turtlack(current_x, current_y));
                        break;
                    case '*':
                        objects.push_back(new Star(current_x, current_y));
                        break;
                    case 'H':
                        objects.push_back(new MovableBlock(current_x, current_y));
                        break;
                    case '|':
                        objects.push_back(new Trap(current_x, current_y));
                        break;
                    case '#':
                        objects.push_back(new Ladder(current_x, current_y));
                        break;
                    case '-':
                        objects.push_back(new Rope(current_x, current_y));
                        break;
                    case 'B':
                        objects.push_back(new TurningBlock(current_x, current_y));
                        break;
                }
            }
            current_x += CHAR_LENGTH_IN_PX;
        }
        current_y += CHAR_LENGTH_IN_PX;
    }
    player = (Playable*)turtix;
}