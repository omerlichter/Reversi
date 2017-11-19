//
// omer lichter
// id: 314649666
//

#ifndef EX1_LOCALPLAYER_H
#define EX1_LOCALPLAYER_H

#include "Player.h"
#include <iostream>

using namespace std;

class LocalPlayer : public Player {
    Point* chooseMove(vector<Point>* points) const ;
};


#endif //EX1_LOCALPLAYER_H
