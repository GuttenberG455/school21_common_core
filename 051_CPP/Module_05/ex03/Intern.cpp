
#include "Intern.hpp"

const std::string Intern::_forms[3] = {
        "Shrubbery Creation",
        "Robotomy Request",
        "Presidential Pardon"
};

Intern::Intern() {}

Intern::Intern(const Intern &old) {
    (void)old;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &old) {
    (void)old;
    return (*this);
}

const char *Intern::WrongFormException::what() const throw() {
    return "Intern.WrongFormException: Wrong type of form.";
}

Form *Intern::makeForm(std::string formName, std::string target) {
    int form_type = -1;
    for (int i = 0; i < 3; i++) {
        if (formName == Intern::_forms[i]) {
            form_type = i;
            break;
        }
    }
    switch (form_type) {
        case 0:
            return new ShrubberyCreationForm(target);
            break;
        case 1:
            return new RobotomyRequestForm(target);
            break;
        case 2:
            return new PresidentialPardonForm(target);
            break;
        default:
            throw Intern::WrongFormException();
            break;
    }
}