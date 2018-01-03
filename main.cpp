#include <iostream>
#include "GameMenuController.h"

using namespace std;

/*
 * main function
 */
int main(int argc, char** argv) {

    GameMenuController gameMenuController;
    int status = gameMenuController.startMenu();
    if (status == 1) {
        return 1;
    }
    return 0;
}