//
// omer lichter
// id: 314649666
//

#ifndef EX1_REVERSILOGIC_H
#define EX1_REVERSILOGIC_H

#include "Board.h"
#include <vector>
#include "Point.h"
#include "Logic.h"

class ReversiLogic : public Logic {
public:
    ReversiLogic();
    vector<Point>* moveOptions(Cell player, Board& board) const ;
    bool makeMove(Cell player, Point& point, Board& board) const ;
    bool isValidPoint(vector<Point>* points, Point &point) const ;

private:
};


#endif //EX1_REVERSILOGIC_H
