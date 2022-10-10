
#include "Form.hpp"

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _isSigned(0),
                                                             _signGrade(signGrade),
                                                             _execGrade(execGrade) {
    if (signGrade < 1 || execGrade < 1)
        throw Form::GradeTooHighException();
    else if (signGrade > 150 || execGrade > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &old) : _name(old._name), _isSigned(old._isSigned), _signGrade(old._signGrade),
                              _execGrade(old._execGrade) {
}

Form::~Form() {
    std::cout << "Form " << this->_name << " was destructed." << std::endl;
}

std::string Form::getName() const {
    return (this->_name);
}

bool Form::getSignStatus() const {
    return (this->_isSigned);
}

int Form::getSignGrade() const {
    return (this->_signGrade);
}

int Form::getExecGrade() const {
    return (this->_execGrade);
}

const char *Form::GradeTooHighException::what() const throw() {
    return "Form.GradeTooHighException: Grade too High.";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Form.GradeTooLowException: Grade too Low.";
}

Form &Form::operator=(const Form &old) {
    this->_isSigned = old._isSigned;
    return (*this);
}

void Form::beSigned(Bureaucrat &bur) {
    if (this->_signGrade < bur.getGrade())
        throw Form::GradeTooLowException();
    this->_isSigned = true;
}

std::ostream &operator<<(std::ostream &out, Form const &form) {
    out << form.getName() << " form. Sign status - " << form.getSignStatus() << " Sign grade - "
        << form.getSignGrade() << " Exec grade - " << form.getExecGrade() << std::endl;
    return (out);
}