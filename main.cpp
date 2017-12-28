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
    // switch for the game type.
    switch (typeOfGame) {
        case 1:
            player1 = new LocalPlayer(drawer, Black);
            player2 = new LocalPlayer(drawer, White);
            break;
        case 2:
            player1 = new LocalPlayer(drawer, Black);
            player2 = new AIPlayer(drawer, White);
            break;
        case 3:
            // get ip and port from file
            ifstream inFile;
            inFile.open("setting_client.txt");
            string ip;
            int port;
            inFile >> ip;
            inFile >> port;
            const char *ip_c = ip.c_str();

            // create client
            RemoteGameClient remoteGameClient(ip_c, port);

            bool joinedGame = false;
            while (!joinedGame) {

                try {
                    // try to connect
                    remoteGameClient.connectToServer();
                } catch (const char *msg) {
                    cout << "Error in Remote Game Client with message: " << msg << endl;
                    // delete memory
                    delete(logic);
                    delete(drawer);
                    return 0;
                }

                int command = drawer->drawServerMenu();
                stringstream commandStream;
                string commandString;
                switch (command) {
                    case 1:
                    {
                        drawer->drawMessage("enter game room name");
                        string gameRoomName = drawer->getCommandFromUser();
                        commandStream << "start <" << gameRoomName << ">";
                        commandString = commandStream.str();
                        try {
                            remoteGameClient.sendToServer(commandString);
                            string status = remoteGameClient.getFromServer();
                            if (status == "1") {
                                joinedGame = true;
                                drawer->drawMessage("waiting for other player to join...");
                            } else if (status == "-1") {
                                drawer->drawMessage("game name already exist");
                                continue;
                            }
                        } catch (const char *message) {
                            cout << "Error in Remote Game Client with message: " << message << endl;
                            return 0;
                        }
                        break;
                    }


                    case 2:
                    {
                        drawer->drawMessage("enter game room name");
                        string gameRoomName = drawer->getCommandFromUser();
                        commandStream << "join <" << gameRoomName << ">";
                        commandString = commandStream.str();
                        try {
                            remoteGameClient.sendToServer(commandString);
                            string status = remoteGameClient.getFromServer();
                            if (status == "1") {
                                joinedGame = true;
                            } else if (status == "-1") {
                                drawer->drawMessage("no available game room with this name");
                                continue;
                            }
                        } catch (const char *message) {
                            cout << "Error in Remote Game Client with message: " << message << endl;
                            return 0;
                        }
                        break;
                    }


                    case 3:
                    {
                        commandStream << "list_games";
                        commandString = commandStream.str();

                        try {
                            remoteGameClient.sendToServer(commandString);
                            drawer->drawMessage("list of game rooms:");
                            string gameRoomName;
                            do {
                                gameRoomName = remoteGameClient.getFromServer();
                                if (gameRoomName != "EndLoop") {
                                    drawer->drawMessage(gameRoomName);
                                }
                            } while (gameRoomName != "EndLoop");

                        } catch (const char *message) {
                            cout << "Error in Remote Game Client with message: " << message << endl;
                            continue;
                        }
                        break;
                    }
                }
            }
            string clientNumber = remoteGameClient.getFromServer();
            if (clientNumber == "1") {
                player1 = new LocalClientPlayer(drawer, Black, remoteGameClient);
                player2 = new RemotePlayer(drawer, White, remoteGameClient);
            } else {
                player1 = new LocalClientPlayer(drawer, White, remoteGameClient);
                player2 = new RemotePlayer(drawer, Black, remoteGameClient);
            }
            break;
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