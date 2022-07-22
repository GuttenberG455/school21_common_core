
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template<class T>
class MutantStack : public std::stack<T> {
public:
    MutantStack() : std::stack<T>() {}
    MutantStack(MutantStack<T> const &old) {
        this->c = old.c;
    }

    ~MutantStack() {}

    MutantStack &operator=(MutantStack<T> const &old) {
        this->c = old.c;
        return (*this);
    }

    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }

};

#endif