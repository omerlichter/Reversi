//
// omer lichter
// id: 314649666
//

#ifndef EX1_LOCALPLAYER_H
#define EX1_LOCALPLAYER_H

#include "Player.h"
#include <iostream>
#include "Drawer.h"

using namespace std;

class LocalPlayer : public Player {
public:
    Point* chooseMove(vector<Point>* points, const Logic& logic, const Board& board) const ;
};


#endif //EX1_LOCALPLAYER_H
