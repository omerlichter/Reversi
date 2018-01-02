#include <iostream>
#include "Game.h"
#include "ReversiLogic.h"
#include "ConsoleDrawer.h"
#include "GameMenuController.h"

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
    GameMenuController gameMenuController;
    int status = gameMenuController.startMenu(&player1, &player2, drawer);
    if (status == 1) {
        delete(logic);
        delete(drawer);
        return 1;
    }

    // create the game
    Game game(BOARD_SIZE, logic, player1, player2, drawer);

    // run the  game
    game.run();

    // delete memory
    delete(logic);
    delete(player1);
    delete(player2);
    delete(drawer);
    return 0;
}