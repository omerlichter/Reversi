//
// Created by omer on 11/30/17.
//

#include "Player.h"

Player::Player() {

}

Player::Player(Cell color) : playerColor_(color) {
}

Cell Player::getPlayerColor() const {
    return this->playerColor_;
}