
#include "Bureaucrat.hpp"

int main() {
    Bureaucrat bur1("Joe", 150);
    Bureaucrat bur2("Vito", 1);
//    Bureaucrat bur3(bur1);
//    Bureaucrat bur4 = bur2;

//    std::cout << bur1;
//    std::cout << bur2;
//    std::cout << bur3;
//    std::cout << bur4;


    std::cout << bur1;
    bur1.incrementGrade();
    std::cout << bur1;
    bur1.decrementGrade();
    std::cout << bur1;

    try {
        bur1.decrementGrade();
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << bur2;

    try {
        bur2.incrementGrade();
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat bur3("Henry", 300);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}