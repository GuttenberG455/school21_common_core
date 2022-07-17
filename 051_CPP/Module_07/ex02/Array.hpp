
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<class T>
class Array {
private:
    unsigned int _size;
    T *_arr;
public:
    Array() : _size(), _arr() {};
    Array(unsigned int size) : _size(size), _arr(new T[size]) {};
    Array(Array<T> const &old) {
        this->_arr = new T[old._size];
        this->_size = old._size;
        for (unsigned int i = 0; i < this->_size; i++) {
            this->_arr[i] = old._arr[i];
        }
    };

    ~Array() {
        delete this->_arr;
    };

    Array<T> &operator=(Array<T> const old) {
        if (this == &old)
            return *old;
        delete this->_arr;
        this->_arr = new T[old._size];
        this->_size = old._size;
        for (unsigned int i = 0; i < this->_size; i++) {
            this->_arr[i] = old._arr[i];
        }
        return (*this);
    };

    unsigned int size() const {
        return this->_size;
    }
};

#endif