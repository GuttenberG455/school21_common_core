
#include "Point.h"

float get_vec_mult(Point const &p1, Point const &p2, Point const &point) {
    return ((p2.getX().toFloat() - p1.getX().toFloat()) * (point.getY().toFloat() - p1.getY().toFloat()) -
            (p2.getY().toFloat() - p1.getY().toFloat()) * (point.getX().toFloat() - p1.getX().toFloat()));
}

bool bsp(Point const &a, Point const &b, Point const &c, Point const &point) {

    float m1 = get_vec_mult(a, b, point);
    float m2 = get_vec_mult(b, c, point);
    float m3 = get_vec_mult(c, a, point);

    if ((m1 == 0 && m2 == 0) || (m2 == 0 && m3 == 0) || (m1 == 0 && m3 == 0)) {
        return (false);
    }
    if ((((m1 == 0) && (m2 > 0) && ( m3 > 0)) ||  ((m1 == 0) && (m2 < 0) && ( m3 < 0))) ||
    (((m2 == 0) && (m1 > 0) && ( m3 > 0)) ||  ((m2 == 0) && (m1 < 0) && ( m3 < 0))) ||
    (((m3 == 0) && (m1 > 0) && ( m2 > 0)) ||  ((m3 == 0) && (m1 < 0) && ( m2 < 0)))) {
        return (false);
    }
    if ((m1 > 0 && m2 > 0 && m3 > 0) || (m1 < 0 && m2 < 0 && m3 < 0)) {
        return (true);
    }
    return (false);

}
