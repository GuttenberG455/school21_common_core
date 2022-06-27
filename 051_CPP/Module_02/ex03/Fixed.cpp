#include "Fixed.h"

const int Fixed::_fract_bits = 8;

Fixed::Fixed() : _value(0) {
}

Fixed::Fixed(int const val) {
    this->_value = val << Fixed::_fract_bits;
}

Fixed::Fixed(const float val) {
    this->_value = roundf(val * (1 << Fixed::_fract_bits));
}

Fixed::Fixed(const Fixed &old) {
    this->_value = old.getRawBits();
}

Fixed::~Fixed() {
}


Fixed &Fixed::operator=(const Fixed &old) {
    this->_value = old.getRawBits();
    return *this;
}

int Fixed::getRawBits() const {
    return this->_value;
}

void Fixed::setRawBits(const int raw) {
    this->_value = raw;
}

float Fixed::toFloat(void) const {
    return ((float) this->_value / (float) (1 << Fixed::_fract_bits));
}

int Fixed::toInt(void) const {
    return (this->_value >> Fixed::_fract_bits);
}

bool Fixed::operator>(const Fixed &fixed) {
    return this->_value > fixed._value;
}

bool Fixed::operator<(const Fixed &fixed) {
    return this->_value < fixed._value;
}

bool Fixed::operator>=(const Fixed &fixed) {
    return this->_value >= fixed._value;
}

bool Fixed::operator<=(const Fixed &fixed) {
    return this->_value <= fixed._value;
}

bool Fixed::operator==(const Fixed &fixed) {
    return this->_value == fixed._value;
}

bool Fixed::operator!=(const Fixed &fixed) {
    return this->_value != fixed._value;
}

Fixed Fixed::operator+(const Fixed &fixed) {
    return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed) {
    return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed) {
    return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed) {
    if (fixed.toFloat() == 0)
        throw std::runtime_error("Division by zero");
    return Fixed(this->toFloat() / fixed.toFloat());
}

Fixed Fixed::operator++(int) {
    Fixed fixed(*this);
    ++_value;
    return fixed;
}

Fixed Fixed::operator++() {
    this->_value++;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed fixed(*this);
    ++_value;
    return fixed;
}

Fixed Fixed::operator--() {
    this->_value--;
    return *this;
}


Fixed &Fixed::min(Fixed &f1, Fixed &f2) {
    if (f1._value < f2._value)
        return f1;
    else
        return f2;
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2) {
    if (f1._value < f2._value)
        return f1;
    else
        return f2;
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2) {
    if (f1._value > f2._value)
        return f1;
    else
        return f2;
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2) {
    if (f1._value > f2._value)
        return f1;
    else
        return f2;
}

std::ostream &operator<<(std::ostream &out, Fixed const &fixed) {
    out << fixed.toFloat();
    return (out);
}

