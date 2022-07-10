
#ifndef INTERN_HPP
#define INTERN_HPP

# include <string>
# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern {
private:
    static const std::string _forms[3];
public:
    Intern();
    Intern(Intern const &old);
    ~Intern();

    Intern &operator=(Intern const &old);

    class WrongFormException: public std::exception {
        virtual const char* what() const throw();
    };

    Form *makeForm(std::string formName, std::string target);
};


#endif
