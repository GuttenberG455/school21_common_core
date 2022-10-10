
#ifndef FIXED_H
#define FIXED_H

#include "iostream"
#include "cmath"

class Fixed {
private:
    int _value;
    static const int _fract_bits;

public:
    Fixed();
    Fixed(int const val);
    Fixed(float const val);
    Fixed(const Fixed &old);
    ~Fixed();

    Fixed &operator= (const Fixed &old);
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &out, Fixed const &fixed);

#endif
