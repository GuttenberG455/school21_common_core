

#include "Span.hpp"

Span::Span() : _size() {}

Span::Span(unsigned int n) : _size(n), {}

Span::Span(const Span &old) {
    this->_size = old._size;
    this->_arr = old._arr;
}

Span::~Span() {}

Span &operator=(Span const &old) {
    this->_size = old._size;
    this->_arr = old._arr;
    return (*this);
}

void Span::addNumber(const int num) {

}


const char *Span::NumLimitException::what() const throw() {
    return "Span.NumLimitException: Span is full.";
}