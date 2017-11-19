//
// omer lichter
// id: 314649666
//

#ifndef EX1_GAME_H
#define EX1_GAME_H


#include "Board.h"
#include "Logic.h"
#include "Player.h"
#include "Drawer.h"

class Game {
public:
    /**
     * constructor
     * @param size - size of the board
     * @param logic - logic of the game
     * @param blackPlayer - black player
     * @param whitePlayer - white player
     */
    Game(int size, Logic* logic, Player* blackPlayer, Player* whitePlayer, Drawer *drawer);
    /**
     * destructor
     */
    ~Game();
    /**
     * run the game
     */
    void run();

private:
    Player* blackPlayer_;
    Player* whitePlayer_;
    Board* board_;
    Logic* logic_;
    Drawer* drawer_;

    /**
    * playe one turn
    * @param playerColor - player turn
    * @return true if there moves to do and false if else
    */
    bool playOneTurn(Cell playerColor);
};


#endif //EX1_GAME_H
