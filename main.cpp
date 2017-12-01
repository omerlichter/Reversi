//
// omer lichter
// id: 314649666
// dvir plaksin
// id: 318947520
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
int main(int argc, char** argv) {

    // create game logic and players .
    Logic* logic = new ReversiLogic();
    Player* player1;
    Player* player2;
    Drawer* drawer = new ConsoleDrawer();

    // draw the open menu, and return the chosen option
    int typeOfGame = drawer->drawOpenMenu();
    if (typeOfGame == 1) {
        player1 = new LocalPlayer(Black);
        player2 = new LocalPlayer(White);
    } else if (typeOfGame == 2) {
        player1 = new LocalPlayer(Black);
        player2 = new AIPlayer(White);
    }

    // create the game
    Game game(BOARD_SIZE, logic, player1, player2, drawer, typeOfGame);

    // run the  game
    game.run();

    // delete memory
    delete(logic);
    delete(player1);
    delete(player2);
    delete(drawer);

    return 0;
}