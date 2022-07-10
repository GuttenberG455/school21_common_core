
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form {
private:
    std::string _target;
public:
    RobotomyRequestForm(std::string const target);
    RobotomyRequestForm(RobotomyRequestForm const &old);
    ~RobotomyRequestForm();

    RobotomyRequestForm &operator=(RobotomyRequestForm const &old);

    void execute(Bureaucrat const &bur) const;
};


#endif
