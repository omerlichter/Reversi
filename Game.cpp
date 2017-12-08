#include "Game.h"

using namespace std;

Game::Game(int size, Logic* logic, Player* player1, Player* player2, Drawer *drawer) {
    this->board_ = new Board (size);
    this->logic_ = logic;
    this->player1_ = player1;
    this->player2_ = player2;
    this->drawer_ = drawer;
}

Game::~Game() {
    delete(this->board_);
}

void Game::run() {

    bool blackPlayerHaveOptions = true;
    bool whitePlayerHaveOptions = true;
    int numberOfFullCells = 0;
    int numberOfCells = this->board_->getSize() * this->board_->getSize();
    int turnNumber = 0;

    Player* blackPlayer;
    Player* whitePlayer;

    // check who is thwe black and white players
    if (this->player1_->getPlayerColor() == Black) {
        blackPlayer = this->player1_;
        whitePlayer = this->player2_;
    } else {
        blackPlayer = this->player2_;
        whitePlayer = this->player1_;
    }

    while ((blackPlayerHaveOptions || whitePlayerHaveOptions) &&
            numberOfFullCells < numberOfCells) {
        // start new turn
        turnNumber++;

        if (turnNumber % 2 == 0) {
            whitePlayerHaveOptions = this->playOneTurn(whitePlayer);
        } else {
            blackPlayerHaveOptions = this->playOneTurn(blackPlayer);
        }

        // add the number of full cells
        numberOfFullCells = this->board_->getNumberOfBlackCells() +
                            this->board_->getNumberOfWhiteCells();
    }

    // print the board on the screen
    this->drawer_->drawBoard(*(this->board_));

    // send end of game to the second player.
    if (turnNumber % 2 == 0) {
        blackPlayer->endOfGame();
    } else {
        whitePlayer->endOfGame();
    }

    // check who win
    if (this->board_->getNumberOfBlackCells() > this->board_->getNumberOfWhiteCells()) {
        this->drawer_->drawEndOfGame(Black);
    } else if (this->board_->getNumberOfWhiteCells() > this->board_->getNumberOfBlackCells()) {
        this->drawer_->drawEndOfGame(White);
    } else {
        this->drawer_->drawEndOfGame(Empty);
    }
}

bool Game::playOneTurn(Player* player) {

    // print the board on the screen
    this->drawer_->drawBoard(*(this->board_));

    // get all optional moves of the player
    vector<Point>* moveOptions = this->logic_->moveOptions(player->getPlayerColor(), *(this->board_));

    // ask the player to choose move
    Point* chosenMove;
    chosenMove = player->chooseMove(moveOptions, *(this->logic_), *(this->board_));

    // if there no moves for this player
    if (chosenMove == NULL) {
        delete(moveOptions);
        return false;
    }

    // play the chosen move
    this->logic_->makeMove(player->getPlayerColor(), *chosenMove, *(this->board_));

    delete(moveOptions);
    delete(chosenMove);
    return true;
}


