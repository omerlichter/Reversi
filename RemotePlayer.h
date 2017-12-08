#ifndef REVERSI_REMOTEPLAYER_H
#define REVERSI_REMOTEPLAYER_H

#include "Player.h"
#include "RemoteGameClient.h"

class RemotePlayer : public Player {
public:
    RemotePlayer(Drawer *drawer, Cell color, RemoteGameClient &remoteGameClient);
    Point* chooseMove(vector<Point>* points, const Logic& logic, const Board& board) const ;

private:
    RemoteGameClient remoteGameClient_;
};


#endif //REVERSI_REMOTEPLAYER_H
