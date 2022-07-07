
#include "Bureaucrat.hpp"

int main() {
	Bureaucrat bur1("Joe", 150);
	Bureaucrat bur2("Vito", 1);

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

	try {
		bur2.incrementGrade();
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

    return 0;
}