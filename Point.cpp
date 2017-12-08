#include "Point.h"

Point::Point(int row, int column) {
    this->row_ = row;
    this->column_ = column;
}

Point::Point(string pointString) {

    string rowString;
    string columnString;
    int i = pointString.find(',');
    if (i != -1) {
        if (i + 2 < pointString.size()) {
            rowString = pointString.substr(0, i);
            columnString = pointString.substr(i + 2);
            istringstream rowBuff(rowString);
            rowBuff >> this->row_;
            istringstream colBuff(columnString);
            colBuff >> this->column_;
        }
    } else {
        this->row_ = 0;
        this->column_ = 0;
    }
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

string Point::toString() const {
    stringstream stringStream;
    stringStream << this->getRow() << ", " << this->getColumn();
    string pointString = stringStream.str();
    return pointString;
}