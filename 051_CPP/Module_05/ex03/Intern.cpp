
#include "Intern.hpp"

const std::string Intern::_forms[3] = {
        "Shrubbery Creation",
        "Robotomy Request",
        "Presidential Pardon"
};

Intern::Intern() {}

Intern::Intern(const Intern &old) {
    (void) old;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &old) {
    (void) old;
    return (*this);
}

const char *Intern::WrongFormException::what() const throw() {
    return "Intern.WrongFormException: Wrong type of form.";
}

Form *Intern::makeForm(std::string formName, std::string target) {
    Form *(*functionPool[3])(std::string const target) = {
            &ShrubberyCreationForm::create,
            &RobotomyRequestForm::create,
            &PresidentialPardonForm::create
    };
    for (int i = 0; i < 3; i++) {
        if (formName == Intern::_forms[i]) {
            return functionPool[i](target);
        }
    }
    throw Intern::WrongFormException();
}