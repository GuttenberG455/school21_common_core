
#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {}

Bureaucrat::Bureaucrat(Bureaucrat const &old) {
    this->_grade = old._grade;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat " << this->_name << " was found dead. RIP" << std::endl;
}

std::string Bureaucrat::getName() const {
    return (this->_name);
}

int Bureaucrat::getGrade() const {
    return (this->_grade);
}

void Bureaucrat::setGrade(const int grade) {
    this->_grade = grade;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &old) {
    this->_grade = old._grade;
    return (*this);
}

void  Bureaucrat::incrementGrade() {
	this->_grade--;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}


void  Bureaucrat::decrementGrade() {
	this->_grade++;
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat.GradeTooHighException: Grade too high.";
}


const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat.GradeTooLowException: Grade too low.";
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bur) {
    out << bur.getName() << ", bureaucrat grade " << bur.getGrade() << "." << std::endl;
    return (out);
}