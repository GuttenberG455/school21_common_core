#include "Fixed.h"

const int Fixed::_fract_bits = 8;

Fixed::Fixed() : _value(0) {
    std::cout << "Default contructor" << std::endl;
}

Fixed::Fixed(int const val) {
    this->_value = val << Fixed::_fract_bits;
    std::cout << "Int contructor" << std::endl;

}

Fixed::Fixed(const float val) {
    this->_value = roundf(val * (1 << Fixed::_fract_bits));
    std::cout << "Float contructor" << std::endl;
}

Fixed::Fixed(const Fixed &old) {
    this->_value = old.getRawBits();
    std::cout << "Copy contructor" << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Destructor" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &old) {
    std::cout << "Copy assignment operator" << std::endl;
    this->_value = old.getRawBits();
    return *this;
}

int Fixed::getRawBits() const {
    std::cout << "Getter" << std::endl;
    return this->_value;
}

void Fixed::setRawBits(const int raw) {
    std::cout << "Setter" << std::endl;
    this->_value = raw;
}

float Fixed::toFloat( void ) const
{
    return ((float)this->_value / (float)(1 << Fixed::_fract_bits));
}

int Fixed::toInt( void ) const
{
    return (this->_value >> Fixed::_fract_bits);
}

std::ostream &operator<<(std::ostream &out, Fixed const &fixed)
{
    out << fixed.toFloat();
    return (out);
}
