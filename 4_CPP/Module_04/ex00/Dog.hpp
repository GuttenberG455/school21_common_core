
#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"

class Dog : public Animal {
public:
    Dog();
    Dog(Dog const &old);
    ~Dog();

    Dog& operator=(const Dog &old);

    void makeSound(void) const;
};


#endif
