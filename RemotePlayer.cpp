#include "RemotePlayer.h"

#define BUFFER_SIZE 255

RemotePlayer::RemotePlayer(Drawer *drawer, Cell color, RemoteGameClient &remoteGameClient) :
        Player(drawer, color), remoteGameClient_(remoteGameClient) {
}


Point* RemotePlayer::chooseMove(vector<Point> *points, const Logic &logic, const Board &board) const {

    // draw on screen
    string message = "waiting for other player's move...";
    this->drawer_->drawMessage(message);

    char moveBuff[BUFFER_SIZE];

    // try to get message from server
    try {
        this->remoteGameClient_.getFromServer(moveBuff);
    } catch (const char *msg) {
        cout << msg << endl;
        return NULL;
    }

    // string of the move
    string pointString(moveBuff);

    if (pointString.compare("NoMove") ==  0) {
        string message = "No possible moves. Play passes back to the other player. ";
        this->drawer_->drawMessage(message);
        return NULL;
    } else {
        // create point from the string
        Point *point = new Point(pointString);

        // draw chosen move
        drawer_->drawChosenPoint(White, *point);
        return point;
    }
}