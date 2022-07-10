
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else {
        this->_grade = grade;
    }
}

Bureaucrat::Bureaucrat(Bureaucrat const &old) : _name(old._name), _grade(old._grade) {
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const {
    return (this->_name);
}

int Bureaucrat::getGrade() const {
    return (this->_grade);
}

void Bureaucrat::setGrade(const int grade) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else {
        this->_grade = grade;
    }
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &old) {
    this->_grade = old._grade;
    return (*this);
}

void Bureaucrat::incrementGrade() {
    this->_grade--;
    if (this->_grade < 1)
        throw Bureaucrat::GradeTooHighException();
}


void Bureaucrat::decrementGrade() {
    this->_grade++;
    if (this->_grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Bureaucrat.GradeTooHighException: Grade too High.";
}


const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Bureaucrat.GradeTooLowException: Grade too Low.";
}

void Bureaucrat::signForm(Form &form) {
    if (this->_grade <= form.getSignGrade())
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    else
        std::cout << this->getName() << " couldn’t sign " << form.getName()
        << " because his grade is too Low" << std::endl;
    form.beSigned(*this);
}

void Bureaucrat::executeForm(Form const &form)
{
    if (!form.getSignStatus()) {
        std::cout << this->getName() << " cannot execute " << form
                  << " because the form is unsigned." << std::endl;
    }
    else if (form.getExecGrade() < this->_grade) {
        std::cout << this->getName() << " cannot execute " << form
                  << " because his grade is too low." << std::endl;
    }
    else {
        std::cout << *this << " executes " << form << std::endl;
    }
    form.execute(*this);
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bur) {
    out << bur.getName() << ", bureaucrat grade " << bur.getGrade() << "." << std::endl;
    return (out);
}