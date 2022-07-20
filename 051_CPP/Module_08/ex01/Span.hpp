
#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span {
private:
    std::vector<int> _arr;
    unsigned int _size;

public:
    Span();
    Span(unsigned int n);
    Span(Span const &old);
    ~Span();

    Span &operator=(Span const &old);

    void addNumber(int const num); // TODO

    int shortestSpan(void); // TODO
    int longestSpan(void); // TODO

    class NumLimitException: public std::exception {
        virtual const char* what() const throw();
    };


};


#endif
