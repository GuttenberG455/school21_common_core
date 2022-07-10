
#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form {
private:
    std::string _target;
public:
    PresidentialPardonForm(std::string const target);
    PresidentialPardonForm(PresidentialPardonForm const &old);
    ~PresidentialPardonForm();

    PresidentialPardonForm &operator=(PresidentialPardonForm const &old);

    void execute(Bureaucrat const &bur) const;
};


#endif
