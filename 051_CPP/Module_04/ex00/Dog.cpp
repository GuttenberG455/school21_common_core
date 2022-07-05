
#include "Dog.hpp"

Dog::Dog() {
    _type = "Dog";
    std::cout << "Default Dog was created" << std::endl;
}

Dog::Dog(const Dog &old) {
    _type=old._type;
}

Dog& Dog::operator= (const Dog &old) {
    _type=old._type;
    return (*this);
}

Dog::~Dog() {
    std::cout <<  _type << " Dog was destructed" << std::endl;
}

void Dog::makeSound() const {
    std::cout <<  _type << " Dog is making a sound: WOOF-WOOF" << std::endl;
}