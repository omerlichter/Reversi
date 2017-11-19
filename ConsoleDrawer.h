//
// omer lichter
// id: 314649666
//

#ifndef EX1_CONSOLEDRAWER_H
#define EX1_CONSOLEDRAWER_H

#include "Board.h"
#include "Drawer.h"

class ConsoleDrawer : public Drawer {
public:
    /**
     * print the board
     * @param board - board of the game
     */
    void drawBoard(Board &board) const ;
    /**
     * print player move title
     * @param playerColor - player color
     */
    void darwPlayerMoveTitle(Cell playerColor) const ;
    /**
     * print possible moves of the player
     * @param moves - possible move vector
     */
    void drawPossibleMovesTitle(vector<Point>* moves) const ;
    /**
     * print player insert dialog
     */
    void drawPlayerInsertDialog() const ;
    /**
     * print message
     * @param message - string of message
     */
    void drawMessage(const string &message) const ;
    /**
     * print end of game
     * @param winPlayerColor - color of win player
     */
    void drawEndOfGame(Cell winPlayerColor) const ;
};


#endif //EX1_CONSOLEDRAWER_H
