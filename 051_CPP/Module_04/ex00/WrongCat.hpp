
#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
    WrongCat();
    WrongCat(WrongCat const &old);
    ~WrongCat();

    WrongCat &operator=(const WrongCat &old);

    void makeSound(void) const;
};


#endif
