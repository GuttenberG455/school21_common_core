#include "Fixed.h"

const int Fixed::_fract_bits = 8;

Fixed::Fixed() : _value(0) {
    std::cout << "Default contructor" << std::endl;
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