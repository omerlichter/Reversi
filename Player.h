#ifndef EX1_PLAYER_H
#define EX1_PLAYER_H

#include "Point.h"
#include "Board.h"
#include "Logic.h"
#include "Drawer.h"
#include <vector>

class Player {
public:
    /**
     * default constructor
     */
    Player(Drawer *drawer);
    /**
     * constructor
     * @param color - player color
     */
    Player(Drawer *drawer, Cell color);
    /**
     * get function
     * @return color of the player
     */
    Cell getPlayerColor() const ;
    /**
     * choose point from the list
     * @param points - points to choose from
     * @return chosen point
     */
    virtual Point* chooseMove(vector<Point>* points, const Logic& logic, const Board& board) const = 0 ;
    /**
     * tell the player that the game end
     */
    virtual void endOfGame() const ;

protected:
    Drawer *drawer_;
    Cell playerColor_;
};


#endif //EX1_PLAYER_H
