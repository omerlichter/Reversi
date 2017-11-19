//
// Created by omer on 11/19/17.
//

#ifndef EX1_AIPLAYER_H
#define EX1_AIPLAYER_H

#include "Player.h"
#include "Logic.h"
#include "Board.h"


class AIPlayer : public Player {
    Point* chooseMove(vector<Point>* points) const ;
};


#endif //EX1_AIPLAYER_H
