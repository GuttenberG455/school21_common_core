
#include "Form.hpp"

int main() {
    Bureaucrat bur1("Polly", 150);
    Form form1("Car rent", 50, 120);

    try {
        bur1.signForm(form1);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    Bureaucrat bur2("Kilian", 30);
    Form form2("Peace treaty", 100, 120);

    std::cout << form2;
    bur2.signForm(form2);
    std::cout << form2;

    std::cout << std::endl;

    try {
        Form form3("Wrong Form", 300, 300);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}