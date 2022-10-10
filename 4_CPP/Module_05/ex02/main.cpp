
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    srand(time(NULL));
    Bureaucrat bur1("Polly", 100);
    ShrubberyCreationForm form_shr("Tree"); // 145, 137

    try {
        bur1.signForm(form_shr);
        form_shr.execute(bur1);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    Bureaucrat bur2("Kelly", 1);
    RobotomyRequestForm form_rob("Angel"); // 72, 45

    try {
        bur2.signForm(form_rob);
        bur2.executeForm(form_rob);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }


    Bureaucrat bur3("Nick", 1);
    PresidentialPardonForm form_pres("Demon Slayer"); // 25, 5

    try {
        bur3.signForm(form_pres);
        bur3.executeForm(form_pres);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}