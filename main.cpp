//
// omer lichter
// id: 314649666
// dvir plaksin
// id: 318947520
//

#include <iostream>
#include <fstream>
#include "Game.h"
#include "ReversiLogic.h"
#include "LocalPlayer.h"
#include "AIPlayer.h"
#include "ConsoleDrawer.h"
#include "RemoteGameClient.h"
#include "LocalClientPlayer.h"
#include "RemotePlayer.h"


#define BOARD_SIZE 4

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
        player1 = new LocalPlayer(drawer, Black);
        player2 = new LocalPlayer(drawer, White);
    } else if (typeOfGame == 2) {
        player1 = new LocalPlayer(drawer, Black);
        player2 = new AIPlayer(drawer, White);
    } else if (typeOfGame == 3) {
        // get ip and port from file
        ifstream inFile;
        inFile.open("setting_client.txt");
        string ip;
        int port;
        inFile >> ip;
        inFile >> port;
        const char *ip_c = ip.c_str();

        RemoteGameClient remoteGameClient(ip_c, port);
        try {
            int clientNumber = remoteGameClient.connectToServer();
            if (clientNumber == 1) {
                player1 = new LocalClientPlayer(drawer, Black, remoteGameClient);
                player2 = new RemotePlayer(drawer, White, remoteGameClient);
            } else {
                player1 = new LocalClientPlayer(drawer, White, remoteGameClient);
                player2 = new RemotePlayer(drawer, Black, remoteGameClient);
            }
        } catch (const char *msg) {
            cout << "Error in Remote Game Client with message: " << msg << endl;
            return 0;
        }
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