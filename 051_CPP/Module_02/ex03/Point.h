
#ifndef POINT_H
#define POINT_H

#include "Fixed.h"

class Point {
private:
    Fixed const _x;
    Fixed const _y;

public:
    Point();
    Point(const Fixed x, const Fixed y);
    Point(const Point &old);
    ~Point();

    Point &operator= (const Point &old);
    Fixed const &getX( void ) const ;
    Fixed const &getY( void ) const ;

};

bool	bsp( Point const &a, Point const &b, Point const &c, Point const &point);

#endif