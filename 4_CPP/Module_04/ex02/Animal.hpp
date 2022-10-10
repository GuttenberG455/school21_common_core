
#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

class Animal {
protected:
    std::string _type;

public:
    virtual ~Animal();

    std::string getType(void) const;
    Animal &operator=(Animal const &old);

    virtual void makeSound(void) const = 0;
};


#endif
