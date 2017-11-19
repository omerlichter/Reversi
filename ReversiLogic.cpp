//
// omer lichter
// id: 314649666
//

#include "ReversiLogic.h"

ReversiLogic::ReversiLogic() {

}

vector<Point>* ReversiLogic::moveOptions(Cell player, Board& board) const {

    vector<Point>* points = new vector<Point>();

    // go over all the cells in the matrix
    for(int i = 0; i < board.getSize(); i++) {
        for (int j = 0; j < board.getSize(); j++) {

            bool isValid = false;
            Cell cellStatus = board.getValueAt(i, j);

            // if the cell status is empty
            if (cellStatus == Empty) {

                // go over all the neighbors of the cell
                for (int u = -1; u < 2; u++) {
                    for (int r = -1; r < 2; r++) {
                        // without the cell itself
                        if (u != 0 || r != 0) {

                            if ((((i + u) >= 0 && (i + u) < board.getSize())
                                 && ((j + r) >= 0 && (j + r) < board.getSize()))
                                && board.getValueAt(i + u, j + r) != Empty
                                && board.getValueAt(i + u, j + r) != player) {
                                // mult value
                                int m = 2;
                                while ((((i + u * m) >= 0 && (i + u * m) < board.getSize())
                                        && ((j + r * m) >= 0 && (j + r * m) < board.getSize()))) {
                                    // get the next neighbors in the path
                                    Cell neighbor = board.getValueAt((i + u * m), (j + r * m));
                                    if (neighbor != player) {
                                        if (neighbor == Empty)
                                            break;
                                        m++;
                                    } else if (neighbor == player) {
                                        isValid = true;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }

                if (isValid == true) {
                    Point point(i + 1, j + 1);
                    points->push_back(point);
                }
            }
        }
    }
    return points;
}

bool ReversiLogic::makeMove(Cell player, Point &point, Board &board) const {

    int row = point.getRow() - 1;
    int column = point.getColumn() - 1;

    bool succeed = board.setValueAt(row, column, player);
    if (succeed == false) {
        return false;
    }

    // go over all the neighbors of the cell
    for (int u = -1; u < 2; u++) {
        for (int r = -1; r < 2; r++) {
            // without the cell itself
            if (u != 0 || r != 0) {

                if ((((row + u) >= 0 && (row + u) < board.getSize())
                     && ((column + r) >= 0 && (column + r) < board.getSize()))
                    && board.getValueAt(row + u, column + r) != Empty
                    && board.getValueAt(row + u, column + r) != player) {
                    // mult value
                    int m = 2;
                    bool isValid = false;
                    while ((((row + u * m) >= 0 && (row + u * m) < board.getSize())
                            && ((column + r * m) >= 0 && (column + r * m) < board.getSize()))) {
                        // get the next neighbors in the path
                        Cell neighbor = board.getValueAt((row + u * m), (column + r * m));
                        if (neighbor != player) {
                            if (neighbor == Empty)
                                break;
                            m++;
                        } else if (neighbor == player) {
                            isValid = true;
                            break;
                        }
                    }

                    if (isValid == true) {
                        for (int i = 0; i < m; i++) {
                            board.setValueAt((row + u * i), (column + r * i), player);
                        }
                    }
                }
            }
        }
    }
    return true;
}

bool ReversiLogic::isValidPoint(vector<Point> *points, Point &point) const {
    for (int i = 0; i < points->size(); i++) {
        if (points->at(i).isEqual(point)) {
            return true;
        }
    }
    return false;
}