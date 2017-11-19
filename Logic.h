//
// omer lichter
// id: 314649666
//

#ifndef EX1_LOGIC_H
#define EX1_LOGIC_H

#include "Board.h"
#include <vector>
#include "Point.h"

class Logic {
public:
    /**
     * retun all move options of the player
     * @param player - player color
     * @param board - board of the game
     * @return all move options of the player
     */
    virtual vector<Point>* moveOptions(Cell player, Board& board) const = 0 ;

    /**
     * make the move
     * @param player - player color
     * @param point - point of the move
     * @param board - board of the game
     * @return true if succeed and false else
     */
    virtual bool makeMove(Cell player, Point& point, Board& board) const = 0 ;

    /**
     * check if point is in vector of points
     * @param points - vector of points
     * @param point - point to check
     * @return true if the point is in the points vector and false else
     */
    virtual bool isValidPoint(vector<Point>* points, Point &point) const = 0 ;

private:
};


#endif //EX1_REVERSILOGIC_H
