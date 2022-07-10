
#include "Intern.hpp"

int main() {
    Intern intern;

    Form *form_schr = intern.makeForm("Shrubbery Creation", "Target1");
    Form *form_rob = intern.makeForm("Robotomy Request", "Target2");
    Form *form_pres = intern.makeForm("Presidential Pardon", "Target3");

    Bureaucrat bur("The Only", 1);


    bur.signForm(*form_schr);
    bur.executeForm(*form_schr);

    bur.signForm(*form_pres);
    bur.executeForm(*form_pres);


    bur.signForm(*form_rob);
    bur.executeForm(*form_rob);

    return 0;
}