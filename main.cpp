//
// omer lichter
// id: 314649666
//

#include <iostream>
#include "Game.h"
#include "ReversiLogic.h"
#include "LocalPlayer.h"
#include "ConsoleDrawer.h"

#define BOARD_SIZE 8

using namespace std;

/*
 * main function
 */
int main() {
    // create game logic and players
    Logic* logic = new ReversiLogic();
    Player* blackPlayer = new LocalPlayer();
    Player* whitePlayer = new LocalPlayer();
    Drawer* drawer = new ConsoleDrawer();

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