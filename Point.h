//
// omer lichter
// id: 314649666
//

#ifndef EX1_POINT_H
#define EX1_POINT_H

#include <string>
using namespace std;

class Point {
public:
    /*
     * constructor
     * @param row - row of the point
     * @param column - column of the point
     */
    Point(int row, int column);
    /*
     * get the row of the point
     */
    int getRow() const ;
    /*
     * set the row of the point
     * @param row - row
     */
    void setRow(int row);
    /*
     * get the column of the point
     */
    int getColumn() const ;
    /*
     * set the column of the point
     * @param column - column
     */
    void setColumn(int column);
    /**
     * check if the points are equal
     * @param point - point to check if equal
     * @return true if equal and false else
     */
    bool isEqual(Point &point) const ;

private:
    int row_;
    int column_;
};


#endif //EX1_POINT_H
