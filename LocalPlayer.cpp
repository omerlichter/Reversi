//
// omer lichter
// id: 314649666
//

#include "LocalPlayer.h"

Point* LocalPlayer::chooseMove(vector<Point> *points) const {

    string input;
    char dummy;
    int row;
    int column;
    Point* point;

    try {
        cin >> input;
        if (input.size() >= 2) {
            row = input[0] - 48;
            column = input[2] - 48;
            point = new Point(row, column);
        } else {
            return NULL;
        }
    } catch (exception e) {
        return NULL;
    }

    return point;
}