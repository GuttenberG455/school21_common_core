
#ifndef FIXED_H
#define FIXED_H

#include "iostream"

class Fixed {
private:
    int _value;
    static const int _fract_bits;

public:
    Fixed();
    Fixed(const Fixed &old);
    ~Fixed();

    Fixed &operator= (const Fixed &old);
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};


#endif
