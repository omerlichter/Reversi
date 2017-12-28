#include "ConsoleDrawer.h"

void ConsoleDrawer::drawBoard(Board &board) const {
    int size = board.getSize();

    // print title
    cout << "Current board:" << endl << endl;

    // print header line
    cout << " |";
    for (int i = 0; i < size; i++) {
        cout << " " << (i + 1) << " |";
    }
    cout << endl;
    cout << "--";
    for (int i = 0; i < size; ++i) {
        cout << "----";
    }
    cout << endl;

    // print every lines
    for (int i = 0; i < size; i++) {
        cout << (i + 1) << "|";
        for (int j = 0; j < size; j++) {
            // print cell status
            switch (board.getValueAt(i, j)) {
                case Black: cout << " X |";
                    break;
                case White: cout << " O |";
                    break;
                case Empty: cout << "   |";
                    break;
            }
        }
        cout << endl;
        cout << "--";
        for (int i = 0; i < size; ++i) {
            cout << "----";
        }
        cout << endl;
    }
}

void ConsoleDrawer::darwPlayerMoveTitle(Cell playerColor) const {
    // print on screen the player color
    switch (playerColor) {
        case Black: cout << "X: ";
            break;
        case White: cout << "O: ";
            break;
    }
    cout << "It's your move." << endl;
}

void ConsoleDrawer::drawPossibleMovesTitle(vector<Point> *moves) const {
    // print on screen the options
    cout << "Your possible moves: ";
    for (int i = 0; i < moves->size(); i++) {
        Point point = moves->at(i);
        cout << "(" << point.toString() << ") ";
    }
    cout << endl << endl;
}

void ConsoleDrawer::drawPlayerInsertDialog() const {
    cout << "Please enter your move row,col (or 'close' for close the game): ";
}

void ConsoleDrawer::drawMessage(const string &message) const {
    cout << message << endl;
}

void ConsoleDrawer::drawEndOfGame(Cell winPlayerColor) const {
    cout << "End of the game." << endl;
    if (winPlayerColor == Black) {
        cout << "Player X win!" << endl;
    } else if (winPlayerColor == White) {
        cout << "Player O win!" << endl;
    } else {
        cout << "Draw!" << endl;
    }
}

int ConsoleDrawer::drawOpenMenu() const {

    int chosenOption;
    do {
        cout << "----Open Menu----" << endl << endl;
        cout << "Choose one of the options:" << endl;
        cout << "1. human vs human" << endl;
        cout << "2. human vs AI" << endl;
        cout << "3. join a remote game" << endl;

        cin >> chosenOption;
        if (chosenOption != 1 && chosenOption != 2 && chosenOption != 3) {
            cout << "not valid option" << endl;
        }

    } while (chosenOption != 1 && chosenOption != 2 && chosenOption != 3);

    return chosenOption;
}

void ConsoleDrawer::drawChosenPoint(Cell playerColor, Point &point) const {
    cout << endl;
    if (playerColor == Black) {
        cout << "X ";
    } else if (playerColor == White) {
        cout << "O ";
    }
    cout << "played ";
    cout << "(" << point.toString() << ")" << endl;
    cout << endl;
}

int ConsoleDrawer::drawServerMenu() const {
    int chosenOption;

    cout << endl;
    do {
        cout << "----Server Menu----" << endl << endl;
        cout << "Choose one of the options:" << endl;
        cout << "1. start new game room" << endl;
        cout << "2. join game room" << endl;
        cout << "3. get list of game rooms" << endl;

        cin >> chosenOption;
        if (chosenOption != 1 && chosenOption != 2 && chosenOption != 3) {
            cout << "not valid option" << endl;
        }

    } while (chosenOption != 1 && chosenOption != 2 && chosenOption != 3);

    return chosenOption;
}

string ConsoleDrawer::getCommandFromUser() const {
    string commandString;
    cin >> commandString;
    return commandString;
}