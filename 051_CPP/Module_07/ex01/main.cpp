
#include <iostream>
#include "iter.hpp"

template<typename T>
void	printKo( T & a ) {

    std::cout << a << "ko" << std::endl;
}

int	main() {

    int arr[] = {0, 1};
    iter(arr, 2, printKo);

    std::cout << std::endl;

    char arr2[] = {'a', 'b', 'c'};
    iter(arr2, 3, printKo);

    std::cout << std::endl;

    std::string arr3[] = {"cow", "bear", "horse"};
    iter(arr3, 3, printKo);
}