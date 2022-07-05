
#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
    Brain *_brain;
public:
    Cat();
    Cat(Cat const &old);
    virtual ~Cat();

    Cat &operator=(const Cat &old);
    Brain *getBrain(void) const;

    void makeSound(void) const;
};


#endif
