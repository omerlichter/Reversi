//
// Created by omer on 12/28/17.
//

#include "GameMenuController.h"

#define BOARD_SIZE 8

int GameMenuController::startMenu() {

    Logic* logic = new ReversiLogic();
    Player* firstPlayer;
    Player* secondPlayer;
    Drawer* drawer = new ConsoleDrawer();

    // draw the open menu, and return the chosen option
    int typeOfGame = drawer->drawOpenMenu();
    // switch for the game type.
    switch (typeOfGame) {
        case 1:
            firstPlayer = new LocalPlayer(drawer, Black);
            secondPlayer = new LocalPlayer(drawer, White);
            break;
        case 2:
            firstPlayer = new LocalPlayer(drawer, Black);
            secondPlayer = new AIPlayer(drawer, White);
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

            int status = this->serverMenu(&firstPlayer, &secondPlayer, &remoteGameClient, drawer);
            if (status == 1) {
                // delete memory
                delete(logic);
                delete(drawer);
                return 1;
            }
    }

    // create the game
    Game game(BOARD_SIZE, logic, firstPlayer, secondPlayer, drawer);

    // run the  game
    game.run();

    // delete memory
    delete(logic);
    delete(firstPlayer);
    delete(secondPlayer);
    delete(drawer);
    return 0;
}

int GameMenuController::serverMenu(Player **firstPlayer, Player **secondPlayer, RemoteGameClient *remoteGameClient ,
                                   Drawer *drawer) {

    bool joinedGame = false;
    while (!joinedGame) {

        try {
            // try to connect
            remoteGameClient->connectToServer();
        } catch (const char *msg) {
            cout << "Error in Remote Game Client with message: " << msg << endl;
            // delete memory
            return 1;
        }

        int command = drawer->drawServerMenu();
        stringstream commandStream;
        string commandString;
        switch (command) {
            case 1:
            {
                drawer->drawMessage("enter game room name");
                string gameRoomName = drawer->getCommandFromUser();
                commandStream << "start " << gameRoomName;
                commandString = commandStream.str();
                try {
                    remoteGameClient->sendToServer(commandString);
                    string status = remoteGameClient->getFromServer();
                    if (status == "1") {
                        joinedGame = true;
                        drawer->drawMessage("waiting for other player to join...");
                    } else if (status == "-1") {
                        drawer->drawMessage("game name already exist");
                        continue;
                    }
                } catch (const char *message) {
                    cout << "Error in Remote Game Client with message: " << message << endl;
                    return 1;
                }
                break;
            }


            case 2:
            {
                drawer->drawMessage("enter game room name");
                string gameRoomName = drawer->getCommandFromUser();
                commandStream << "join " << gameRoomName;
                commandString = commandStream.str();
                try {
                    remoteGameClient->sendToServer(commandString);
                    string status = remoteGameClient->getFromServer();
                    if (status == "1") {
                        joinedGame = true;
                    } else if (status == "-1") {
                        drawer->drawMessage("no available game room with this name");
                        continue;
                    }
                } catch (const char *message) {
                    cout << "Error in Remote Game Client with message: " << message << endl;
                    return 1;
                }
                break;
            }


            case 3:
            {
                commandStream << "list_games";
                commandString = commandStream.str();

                try {
                    remoteGameClient->sendToServer(commandString);
                    drawer->drawMessage("list of game rooms:");
                    string gameRoomName;
                    do {
                        gameRoomName = remoteGameClient->getFromServer();
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

    string clientNumber;
    try {
        clientNumber = remoteGameClient->getFromServer();
    } catch (const char *message) {
        cout << message << endl;
        return 1;
    }
    if (clientNumber == "1") {
        *firstPlayer = new LocalClientPlayer(drawer, Black, *remoteGameClient);
        *secondPlayer = new RemotePlayer(drawer, White, *remoteGameClient);
    } else {
        *firstPlayer = new LocalClientPlayer(drawer, White, *remoteGameClient);
        *secondPlayer = new RemotePlayer(drawer, Black, *remoteGameClient);
    }
    return 0;
}