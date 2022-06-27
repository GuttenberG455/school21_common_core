
#include "Point.h"

Point::Point() : _x(0), _y(0) {}

Point::Point(const Fixed x, const Fixed y) : _x(x), _y(y) {
}

Point::Point(const Point &old) {
    *this = old;
}

Point::~Point() {}

Point &Point::operator=(const Point &old) {
    (Fixed)this->_x = (Fixed)old._x;
    (Fixed)this->_y = (Fixed)old._y;
    return *this;
}

Fixed const &Point::getX() const {
    return this->_x;
}

Fixed const &Point::getY() const {
    return this->_y;
}