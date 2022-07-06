
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
     void setName(std::string const name);
     void setGrade(int const grade);

     Bureaucrat &operator=(Bureaucrat const &old);

};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bur);

#endif
