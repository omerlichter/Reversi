#include "LocalPlayer.h"

LocalPlayer::LocalPlayer(Drawer *drawer, Cell color) : Player(drawer, color) {
}

Point* LocalPlayer::chooseMove(vector<Point>* points, const Logic& logic, const Board& board) const {

    string input;
    int row;
    int column;
    Point* point;
    bool validPoint;

    // if there no moves for this player
    if (points->size() == 0) {
        string message = "No possible moves. Play passes back to the other player. ";
        this->drawer_->drawMessage(message);
        return NULL;
    }

    // print the player move title
    this->drawer_->darwPlayerMoveTitle(this->getPlayerColor());

    // print the possible moves
    this->drawer_->drawPossibleMovesTitle(points);

    do {
        // print
        this->drawer_->drawPlayerInsertDialog();

        validPoint = true;
        cin >> input;
        int i = input.find(',');
        if (i != -1) {
            string rowString = input.substr(0, i);
            string colString = input.substr(i + 1);
            istringstream rowBuff(rowString);
            rowBuff >> row;
            istringstream colBuff(colString);
            colBuff >> column;
            point = new Point(row, column);
        } else {
            validPoint = false;
            point = new Point(0, 0);
        }

        // check validation
        if (validPoint == true) {
            validPoint = logic.isValidPoint(points, *point);
        }

        if (validPoint == false) {
            delete(point);
            string message = "not Valid Point";
            this->drawer_->drawMessage(message);
        }
    } while (validPoint == false);

    return point;
}