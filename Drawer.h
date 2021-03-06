#ifndef EX1_DRAWER_H
#define EX1_DRAWER_H

#include <iostream>
#include <string>
#include <vector>
#include "Point.h"
#include "Board.h"

using namespace std;

class Drawer {
public:
    /**
     * print board on screen
     * @param board - board of the game
     */
    virtual void drawBoard(Board &board) const = 0 ;
    /**
     * draw player moves title
     * @param playerColor - color of the player
     */
    virtual void darwPlayerMoveTitle(Cell playerColor) const = 0 ;
    /**
     * print possible moves
     * @param moves - possible moves vector
     */
    virtual void drawPossibleMovesTitle(vector<Point>* moves) const = 0 ;
    /**
     * print player insert dialog
     */
    virtual void drawPlayerInsertDialog() const = 0;
    /**
     * print message
     * @param message - string of message
     */
    virtual void drawMessage(const string &message) const = 0 ;
    /**
     * print end of the gamee
     * @param winPlayerColor - color of win player
     */
    virtual void drawEndOfGame(Cell winPlayerColor) const = 0 ;
    /**
     * print the open menu
     * @return the chosen option
     */
    virtual int drawOpenMenu() const  = 0;
    /**
     * print the chosen point
     */
    virtual void drawChosenPoint(Cell playerColor, Point& point) const  = 0;

    virtual int drawServerMenu() const = 0;

    virtual string getCommandFromUser() const = 0 ;
};


#endif //EX1_DRAWER_H
