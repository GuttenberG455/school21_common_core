
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>

class ItemNotFoundException : public std::exception {
public:
    char const *what() const throw() {
        return "ItemNotFoundException: Item not found.";
    }
};

template<typename T>
typename T::iterator easyfind(T &array, int item) {
    typename T::iterator iter = std::find(array.begin(), array.end(), item);
    if (iter == array.end())
        throw ItemNotFoundException();
    return iter;
}

#endif