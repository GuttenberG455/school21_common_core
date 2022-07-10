
#ifndef FORM_HPP
#define FORM_HPP
class Form;
#include "Bureaucrat.hpp"

class Form {
private:
    const std::string _name;
    bool _isSigned;
    const int _signGrade;
    const int _execGrade;

public:
    Form(std::string name, int signGrade, int execGrade);
    Form(Form const &old);
    ~Form();

    std::string getName(void) const;
    bool getSignStatus(void) const;
    int getSignGrade(void) const;
    int getExecGrade(void) const;

    class GradeTooHighException: public std::exception {
        virtual const char* what() const throw();
    };
    class GradeTooLowException: public std::exception {
        virtual const char* what() const throw();
    };
    class UnsignedFormException: public std::exception {
        virtual const char* what() const throw();
    };

    Form &operator=(Form const &old);

    void beSigned(Bureaucrat const &bur);
    virtual void execute(Bureaucrat const &bur) const;
};

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif
