#include "Player.h"

Player::Player(Drawer *drawer) : drawer_(drawer) {

}

Player::Player(Drawer *drawer, Cell color) : drawer_(drawer), playerColor_(color) {
}

Cell Player::getPlayerColor() const {
    return this->playerColor_;
}

void Player::endOfGame() const {

}