//
// omer lichter
// id: 314649666
//

#include "Game.h"

using namespace std;

Game::Game(int size, Logic* logic, Player* blackPlayer, Player* whitePlayer, Drawer *drawer) {
    this->board_ = new Board (size);
    this->logic_ = logic;
    this->blackPlayer_ = blackPlayer;
    this->whitePlayer_ = whitePlayer;
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

    while ((blackPlayerHaveOptions || whitePlayerHaveOptions) &&
            numberOfFullCells < numberOfCells) {
        // start new turn
        turnNumber++;

        if (turnNumber % 2 == 0) {
            whitePlayerHaveOptions = this->playOneTurn(White);
        } else {
            blackPlayerHaveOptions = this->playOneTurn(Black);
        }

        // add the number of full cells
        numberOfFullCells = this->board_->getNumberOfBlackCells() +
                            this->board_->getNumberOfWhiteCells();
    }

    // print the board on the screen
    this->drawer_->drawBoard(*(this->board_));

    // check who win
    if (this->board_->getNumberOfBlackCells() > this->board_->getNumberOfWhiteCells()) {
        this->drawer_->drawEndOfGame(Black);
    } else if (this->board_->getNumberOfWhiteCells() > this->board_->getNumberOfBlackCells()) {
        this->drawer_->drawEndOfGame(White);
    } else {
        this->drawer_->drawEndOfGame(Empty);
    }
}

bool Game::playOneTurn(Cell playerColor) {
    string message;

    // print the board on the screen
    this->drawer_->drawBoard(*(this->board_));
    this->drawer_->darwPlayerMoveTitle(playerColor);

    // get all optional moves of the player
    vector<Point>* moveOptions = this->logic_->moveOptions(playerColor, *(this->board_));

    // if there no moves for this player
    if (moveOptions->size() == 0) {
        message = "No possible moves. Play passes back to the other player. ";
        this->drawer_->drawMessage(message);
        delete(moveOptions);
        return false;
    }

    this->drawer_->drawPossibleMovesTitle(moveOptions);

    // ask the player to choose move
    Point* chosenMove;
    bool validPoint = false;
    do {
        // print
        this->drawer_->drawPlayerInsertDialog();

        if (playerColor == Black) {
            chosenMove = this->blackPlayer_->chooseMove(moveOptions);
        } else if (playerColor == White) {
            chosenMove = this->whitePlayer_->chooseMove(moveOptions);
        }
        // check validation
        if (chosenMove != NULL) {
            validPoint = this->logic_->isValidPoint(moveOptions, *chosenMove);
        } else {
            validPoint = false;
        }
        if (validPoint == false) {
            delete(chosenMove);
            message = "not Valid Point";
            this->drawer_->drawMessage(message);
        }

    } while (validPoint == false);


    // play the chosen move
    this->logic_->makeMove(playerColor, *chosenMove, *(this->board_));

    delete(moveOptions);
    delete(chosenMove);
    return true;
}


