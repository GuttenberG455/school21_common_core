
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

    class NumLimitException: public std::exception {
        virtual const char* what() const throw();
    };

    class TooFewNumsException: public std::exception {
        virtual const char* what() const throw();
    };

    void addNumber(int const num);
    void addNumber(std::vector<int>::iterator const &start, std::vector<int>::iterator const &end);
    int shortestSpan(void);
    int longestSpan(void);


};


#endif
