//
// Created by omer on 12/28/17.
//

#ifndef REVERSI_GAMEMENUCONTROLLER_H
#define REVERSI_GAMEMENUCONTROLLER_H

#include "Player.h"
#include "LocalClientPlayer.h"
#include "Drawer.h"
#include "RemotePlayer.h"
#include "AIPlayer.h"
#include "LocalPlayer.h"
#include <iostream>
#include <fstream>

using namespace std;

class GameMenuController {
public:
    int startMenu(Player **firstPlayer, Player **secondPlayer, Drawer *drawer);

private:
    int serverMenu(Player **firstPlayer, Player **secondPlayer, Drawer *drawer);
};


#endif //REVERSI_GAMEMENUCONTROLLER_H
