
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat {
private:
    const std::string _name;
    int _grade;

public:
    Bureaucrat(std::string name, int grade);
    Bureaucrat(Bureaucrat const &old);
    ~Bureaucrat();

    std::string getName(void) const;
    int getGrade(void) const;
    void setGrade(int const grade);

    void incrementGrade(void);
    void decrementGrade(void);

    class GradeTooHighException: public std::exception {
        virtual const char* what() const throw();
    };
    class GradeTooLowException: public std::exception {
        virtual const char* what() const throw();
    };

    Bureaucrat &operator=(Bureaucrat const &old);

};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bur);

#endif