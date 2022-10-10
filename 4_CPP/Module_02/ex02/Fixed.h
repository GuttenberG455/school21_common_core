
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

    bool operator> (const Fixed &fixed);
    bool operator< (const Fixed &fixed);
    bool operator>= (const Fixed &fixed);
    bool operator<= (const Fixed &fixed);
    bool operator== (const Fixed &fixed);
    bool operator!= (const Fixed &fixed);
    Fixed operator+ (const Fixed &fixed);
    Fixed operator- (const Fixed &fixed);
    Fixed operator* (const Fixed &fixed);
    Fixed operator/ (const Fixed &fixed);
    Fixed operator++ (int);
    Fixed operator++ ();
    Fixed operator-- (int);
    Fixed operator-- ();

    static Fixed& max(Fixed &f1, Fixed &f2);
    static const Fixed& max(Fixed const &f1, Fixed const &f2);
    static Fixed& min(Fixed &f1, Fixed &f2);
    static const Fixed& min(Fixed const &f1, Fixed const &f2);

};

std::ostream &operator<<(std::ostream &out, Fixed const &fixed);

#endif
