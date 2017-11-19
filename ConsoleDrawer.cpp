//
// omer lichter
// id: 314649666
//

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
        cout << "(" << point.getRow() << ", " << point.getColumn() << ") ";
    }
    cout << endl << endl;
}

void ConsoleDrawer::drawPlayerInsertDialog() const {
    cout << "Please enter your move row,col: ";
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