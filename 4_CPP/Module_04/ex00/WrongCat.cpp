
#include "WrongCat.hpp"

WrongCat::WrongCat(){
    _type = "WrongCat";
    std::cout << "Wrong Cat was created" << std::endl;
}

WrongCat::WrongCat(const WrongCat &old) {
    _type = old.getType();
}

WrongCat::~WrongCat() {
    std::cout << "Wrong Cat was destructed" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &old) {
    _type = old.getType();
    return (*this);
}

void WrongCat::makeSound(void) const {
    std::cout << _type << " Wrong Cat is making a wrong sound: MUU-MUU" << std::endl;
}
