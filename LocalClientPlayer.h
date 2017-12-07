//
// Created by omer on 12/1/17.
//

#ifndef REVERSI_LOCALCLIENTPLAYER_H
#define REVERSI_LOCALCLIENTPLAYER_H

#include "Player.h"
#include "RemoteGameClient.h"

class LocalClientPlayer : public Player {
public:
    LocalClientPlayer(Drawer *drawer, Cell color, RemoteGameClient &remoteGameClient);
    Point* chooseMove(vector<Point>* points, const Logic& logic, const Board& board) const ;
    /**
     * send to server this is end of game
     */
    void endOfGame() const ;

private:
    RemoteGameClient remoteGameClient_;
};


#endif //REVERSI_LOCALCLIENTPLAYER_H
