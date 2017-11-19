//
// omer lichter
// id: 314649666
//

#ifndef EX1_BOARD_H
#define EX1_BOARD_H

//#include "Drawer.h"

enum Cell {Black, White, Empty};

class Board {
public:
    /**
     * constructor
     * @param size - size of the matrix
     * @param drawer - drawer
     */
    Board(int size);
    /**
     * destructor
     */
    ~Board();
    /**
     * print the board on the screen
     */
    void print() const ;
    /**
     * return the size of the board
     * @return the size of the board
     */
    int getSize() const ;
    /**
     * return the value of the cell
     * @param row - row of the cell
     * @param column - column of the cell
     * @return the value of the cell
     */
    Cell getValueAt(int row, int column) const ;
    /**
     * set value at point of the matrix
     * @param row - row
     * @param column - column
     * @param cellStatus - status of cell
     * @return if the action success
     */
    bool setValueAt(int row, int column, Cell cellStatus) ;
    /**
     * return the number of the black cells
     * @return the number of the black cells
     */
    int getNumberOfBlackCells() const ;
    /**
     * return the number of the white cells
     * @return the number of the white cells
     */
    int getNumberOfWhiteCells() const ;

private:
    Cell** board_;
    int size_;
    int blackCells_;
    int whiteCells_;
};


#endif //EX1_BOARD_H
