#ifndef EX1_LOCALPLAYER_H
#define EX1_LOCALPLAYER_H

#include "Player.h"
#include <iostream>
#include <sstream>
#include "Drawer.h"

using namespace std;

class LocalPlayer : public Player {
public:
    LocalPlayer(Drawer *drawer, Cell color);
    Point* chooseMove(vector<Point>* points, const Logic& logic, const Board& board) const ;
};


#endif //EX1_LOCALPLAYER_H
