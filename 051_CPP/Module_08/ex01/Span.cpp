
#include "Span.hpp"

Span::Span() : _size() {}

Span::Span(unsigned int n) : _size(n) {}

Span::Span(const Span &old) {
    this->_size = old._size;
    this->_arr = old._arr;
}

Span::~Span() {}

Span &Span::operator=(Span const &old) {
    this->_size = old._size;
    this->_arr = old._arr;
    return (*this);
}

const char *Span::NumLimitException::what() const throw() {
    return "Span.NumLimitException: Span is full.";
}

const char *Span::TooFewNumsException::what() const throw() {
    return "Span.TooFewNumsException: Too few numbers in Span.";
}

void Span::addNumber(const int num) {
    if (_arr.size() == this->_size)
        throw NumLimitException();
    _arr.push_back(num);
}

void Span::addNumber(std::vector<int>::iterator const &start, std::vector<int>::iterator const &end) {

    for (std::vector<int>::iterator it = start; it != end; it++) {
        if (this->_arr.size() == this->_size) {
            throw NumLimitException();
        }
        this->_arr.push_back(*it);
    }
}

int Span::shortestSpan() {
    if (_arr.size() <= 1)
        throw TooFewNumsException();

    int min = abs(*(this->_arr.begin()) - *(this->_arr.begin() + 1));
    for (std::vector<int>::iterator it = this->_arr.begin(); it != this->_arr.end(); it++) {
        for (std::vector<int>::iterator it2 = it + 1; it2 != this->_arr.end(); it2++) {
            if (abs(*it2 - *it) < min) {
                min = abs(*it2 - *it);
            }
        }
    }
    return min;
}

int Span::longestSpan() {
    if (_arr.size() <= 1)
        throw TooFewNumsException();

    int max = abs(*(this->_arr.begin()) - *(this->_arr.begin() + 1));
    for (std::vector<int>::iterator it = this->_arr.begin(); it != this->_arr.end(); it++) {
        for (std::vector<int>::iterator it2 = it + 1; it2 != this->_arr.end(); it2++) {
            if (abs(*it2 - *it) > max) {
                max = abs(*it2 - *it);
            }
        }
    }
    return max;
}
