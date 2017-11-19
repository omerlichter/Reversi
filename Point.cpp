//
// omer lichter
// id: 314649666
//

#include "Point.h"

Point::Point(int row, int column) {
    this->row_ = row;
    this->column_ = column;
}

int Point::getRow() const {
    return this->row_;
}

int Point::getColumn() const {
    return this->column_;
}

void Point::setRow(int row) {
    this->row_ = row;
}

void Point::setColumn(int column) {
    this->column_ = column;
}

bool Point::isEqual(Point &point) const {
    if (point.getRow() == this->getRow() &&
            point.getColumn() == this->getColumn()) {
        return true;
    }
    return false;
}