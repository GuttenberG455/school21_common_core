
#include "Cat.hpp"

Cat::Cat() {
    _type = "Cat";
    std::cout << "Default Cat was created" << std::endl;
}

Cat::Cat(const Cat &old) {
    _type = old.getType();
}

Cat::~Cat() {
    std::cout << _type << " Cat was destructed" << std::endl;
}

Cat &Cat::operator=(const Cat &old) {
    _type = old.getType();
    return (*this);
}

void Cat::makeSound() const {
    std::cout << _type << " Cat is making a sound: MEOW-MEOW" << std::endl;
}