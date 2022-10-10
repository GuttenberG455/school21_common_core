
#include "easyfind.hpp"
#include <vector>

int main() {

    int arr[] = {2, 4, 6, 8, 10, 1, 3, 5, 7, 9};
    std::vector<int> v(arr, arr + 10);

    try {
        std::cout << *easyfind(v, 7) << std::endl;
        std::cout << *easyfind(v, 21) << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}