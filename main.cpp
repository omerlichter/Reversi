//
// omer lichter
// id: 314649666
//

#include <iostream>
#include "Game.h"
#include "ReversiLogic.h"
#include "LocalPlayer.h"
#include "AIPlayer.h"
#include "ConsoleDrawer.h"

#define BOARD_SIZE 8

using namespace std;

/*
 * main function
 */
int main() {
    // create game logic and players .
    Logic* logic = new ReversiLogic();
    Player* blackPlayer;
    Player* whitePlayer;
    Drawer* drawer = new ConsoleDrawer();

    // draw the open menu, and return the chosen option
    int typeOfGame = drawer->drawOpenMenu();
    if (typeOfGame == 1) {
        blackPlayer = new LocalPlayer();
        whitePlayer = new LocalPlayer();
    } else if (typeOfGame == 2) {
        blackPlayer = new LocalPlayer();
        whitePlayer = new AIPlayer();
    }

    // create the game
    Game game(BOARD_SIZE, logic, blackPlayer, whitePlayer, drawer);

    // run the  game
    game.run();

    // delete memory
    delete(logic);
    delete(blackPlayer);
    delete(whitePlayer);
    delete(drawer);

    return 0;
}