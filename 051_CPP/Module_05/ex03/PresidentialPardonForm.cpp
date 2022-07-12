
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : Form(target, 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &old) : Form(old), _target(old._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &old) {
    this->_target = old._target;
    return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat &bur) const {
    Form::execute(bur);
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
}

Form *PresidentialPardonForm::create(std::string const target) {
    return new PresidentialPardonForm(target);
}