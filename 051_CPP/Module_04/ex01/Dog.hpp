
#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
    Brain *_brain;
public:
    Dog();
    Dog(Dog const &old);
    virtual ~Dog();

    Dog& operator=(const Dog &old);
    Brain *getBrain(void) const;

    void makeSound(void) const;
};


#endif
