//
// omer lichter
// id: 314649666
//

#ifndef EX1_AIPLAYER_H
#define EX1_AIPLAYER_H

#include "Player.h"


class AIPlayer : public Player {
public:
    AIPlayer(Cell color);
    Point* chooseMove(vector<Point>* points, const Logic& logic, const Board& board) const ;

private:
    /**
     * calculate the maximum points that the opp can rich
     * @param logic - logic of the game
     * @param board - current status of board
     * @return the maximum points that the opp can rich
     */
    int maxOppScore(const Logic& logic, Board& board) const ;
};


#endif //EX1_AIPLAYER_H
