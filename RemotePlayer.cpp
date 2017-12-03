//
// Created by omer on 12/1/17.
//

#include "RemotePlayer.h"

RemotePlayer::RemotePlayer(Drawer *drawer, Cell color, RemoteGameClient &remoteGameClient) :
        Player(drawer, color), remoteGameClient_(remoteGameClient) {
}


Point* RemotePlayer::chooseMove(vector<Point> *points, const Logic &logic, const Board &board) const {
    char moveBuff[10];
    this->remoteGameClient_.getFromServer(moveBuff);
    string pointString(moveBuff);
    if (pointString.compare("NoMove") ==  0) {
        string message = "No possible moves. Play passes back to the other player. ";
        this->drawer_->drawMessage(message);
        return NULL;
    } else {
        Point *point = new Point(pointString);
        return point;
    }
}