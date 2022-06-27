
#include <iostream>
#include "Point.h"

int main(void) {

    Point obj;
    Point const point(Fixed(17), Fixed(3));
    Point const a(Fixed(17), Fixed(17));
    Point const b(Fixed(11), Fixed(1));
    Point const c(Fixed(2), Fixed(2));

    if (bsp(a, b, c, point))
        std::cout << "Point is inside the triangle" << std::endl;
    else
        std::cout << "Point is outside" << std::endl;

    return 0;
}