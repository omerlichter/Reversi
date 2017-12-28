#include "LocalClientPlayer.h"

#define BUFFER_SIZE 255

LocalClientPlayer::LocalClientPlayer(Drawer *drawer, Cell color, RemoteGameClient &remoteGameClient) :
    Player(drawer, color), remoteGameClient_(remoteGameClient){

}

Point* LocalClientPlayer::chooseMove(vector<Point> *points, const Logic &logic, const Board &board) const {

    string input;
    int row;
    int column;
    Point* point;
    bool validPoint;

    // if there no moves for this player
    if (points->size() == 0) {
        string message = "No possible moves. Play passes back to the other player. ";
        this->drawer_->drawMessage(message);

        // send to the server
        try {
            this->remoteGameClient_.sendToServer("NoMove");
        } catch (const char *message) {
            return new Point(-1, -1);
        }
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

    // send to the server
    string pointString = point->toString();

    try {
        this->remoteGameClient_.sendToServer(pointString);
    } catch (const char *msg) {
        return new Point(-1, -1);
    }
    return point;
}

void LocalClientPlayer::endOfGame() const {
    this->remoteGameClient_.sendToServer("END");
}