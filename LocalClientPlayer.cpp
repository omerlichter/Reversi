//
// Created by omer on 12/1/17.
//

#include "LocalClientPlayer.h"

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
        const char *moveBuff = "NoMove";
        this->remoteGameClient_.sendToServer(moveBuff);

        return NULL;
    }

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
    const char *pointBuff = pointString.c_str();
    char moveBuff[10];
    for (int i = 0; i < 10; i++) {
        if (i < pointString.size()) {
            moveBuff[i] = pointBuff[i];
        } else {
            moveBuff[i] = '\0';
        }
    }
    this->remoteGameClient_.sendToServer(moveBuff);

    return point;
}