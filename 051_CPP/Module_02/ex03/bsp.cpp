
#include "Point.h"

float get_mult(Point const &p1, Point const &p2, Point const &p3) {
    return abs((p1.getX().toFloat() * (p2.getY().toFloat() - p3.getY().toFloat()) +
                p2.getX().toFloat() * (p3.getY().toFloat() - p1.getY().toFloat()) +
                p3.getX().toFloat() * (p1.getY().toFloat() - p2.getY().toFloat())));
}


bool bsp(Point const &a, Point const &b, Point const &c, Point const &point) {

    float m = get_mult(a, b, c);
    float m1 = get_mult(point, b, c);
    float m2 = get_mult(point, a, c);
    float m3 = get_mult(point, a, b);

    return (m == m1 + m2 + m3);
}
