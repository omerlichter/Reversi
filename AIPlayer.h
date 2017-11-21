//
// Created by omer on 11/19/17.
//

#ifndef EX1_AIPLAYER_H
#define EX1_AIPLAYER_H

#include "Player.h"


class AIPlayer : public Player {
public:
    Point* chooseMove(vector<Point>* points, const Logic& logic, const Board& board) const ;

private:
    /**
     *
     * @param logic
     * @param board
     * @return
     */
    int maxOppScore(const Logic& logic, Board& board) const ;
};


#endif //EX1_AIPLAYER_H
