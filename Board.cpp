#include "Board.h"
#include <iostream>

using namespace std;

Board::Board(int size) {

    this->whiteCells_ = 2;
    this->blackCells_ = 2;
    this->size_ = size;

    // create the array of arrays of chars
    this->board_ = new Cell* [size];
    for (int i = 0; i < size; i++) {
        this->board_[i] = new Cell[size];
    }

    // find half of board
    int halfSize = size / 2;

    // set start board
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if ((i == (halfSize - 1) && j == (halfSize - 1)) || (i == halfSize && j == halfSize)) {
                this->board_[i][j] = White;
            }
            else if (((i == halfSize - 1) && j == halfSize) || (i == halfSize && j == (halfSize - 1))) {
                this->board_[i][j] = Black;
            } else {
                this->board_[i][j] = Empty;
            }
        }
    }
}

Board::Board(const Board &board) {
    this->whiteCells_ = board.getNumberOfWhiteCells();
    this->blackCells_ = board.getNumberOfBlackCells();
    this->size_ = board.getSize();

    this->board_ = new Cell* [this->getSize()];
    for (int i = 0; i < this->getSize(); i++) {
        this->board_[i] = new Cell[this->getSize()];
    }

    // set start board
    for (int i = 0; i < this->getSize(); i++) {
        for (int j = 0; j < this->getSize(); j++) {
            this->board_[i][j] = board.getValueAt(i, j);
        }
    }
}

Board::~Board() {
    for (int i = 0; i < this->size_; i++) {
        delete[](this->board_[i]);
    }

    delete[](this->board_);
}

void Board::print() const {

}

int Board::getSize() const {
    return this->size_;
}

Cell Board::getValueAt(int row, int column) const {
    if (row < this->getSize() && row >= 0 && column < this->getSize() && column >= 0)
    return this->board_[row][column];
}

bool Board::setValueAt(int row, int column, Cell cellStatus) {
    if (row >= 0 && row < this->getSize()
            && column >= 0 && column < this->getSize()) {
        Cell lastCellStatus = this->getValueAt(row, column);
        this->board_[row][column] = cellStatus;
        if (lastCellStatus == Black && cellStatus == White) {
            this->whiteCells_++;
            this->blackCells_--;
        } else if (lastCellStatus == White && cellStatus == Black) {
            this->blackCells_++;
            this->whiteCells_--;
        } else if (lastCellStatus == Empty && cellStatus == White) {
            this->whiteCells_++;
        } else if (lastCellStatus == Empty && cellStatus == Black) {
            this->blackCells_++;
        }
        return true;
    }
    return false;
}

int Board::getNumberOfBlackCells() const {
    return this->blackCells_;
}

int Board::getNumberOfWhiteCells() const {
    return this->whiteCells_;
}

bool Board::operator==(Board &board1) const {

    if (board1.getSize() != this->getSize()) {
        return false;
    }

    for (int i = 0; i < board1.getSize(); i++) {
        for (int j = 0; j < board1.getSize(); j++) {
            if (board1.getValueAt(i, j) != this->getValueAt(i, j)) {
                return false;
            }
        }
    }
    return true;
}
