//
// Created by omer on 11/30/17.
//

#include "Player.h"

Player::Player(Drawer *drawer) : drawer_(drawer) {

}

Player::Player(Drawer *drawer, Cell color) : drawer_(drawer), playerColor_(color) {
}

Cell Player::getPlayerColor() const {
    return this->playerColor_;
}