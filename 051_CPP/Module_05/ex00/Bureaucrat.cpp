
#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {}

Bureaucrat::Bureaucrat(Bureaucrat const &old) {
    this->_name = old._name;
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

void Bureaucrat::setName(const std::string name) {
    this->_name = name;
}

void Bureaucrat::setGrade(const int grade) {
    this->_grade = grade;
}

Bureaucrat &operator=(Bureaucrat const &old) {
    this->_name = old._name;
    this->_grade = old._grade;
    return (*this);
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bur) {
    out << bur.getName() << " , bureaucrat grade " << bur.getGrade() << "." << std::endl;
    return (out);
}