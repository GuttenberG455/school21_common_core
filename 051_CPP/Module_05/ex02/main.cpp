
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
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
        form_rob.execute(bur2);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }


    Bureaucrat bur3("Nick", 1);
    PresidentialPardonForm form_pres("Demon Slayer"); // 25, 5

    try {
        bur3.signForm(form_pres);
        form_pres.execute(bur3);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}