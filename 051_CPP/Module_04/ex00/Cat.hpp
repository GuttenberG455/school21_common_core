
#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"

class Cat : public Animal {
public:
    Cat();
    Cat(Cat const &old);
    ~Cat();

    Cat &operator=(const Cat &old);

    void makeSound(void) const;
};


#endif
