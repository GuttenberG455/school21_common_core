
#include "Animal.hpp"

Animal::~Animal() {
    std::cout << _type << " Animal was destructed" << std::endl;
}

std::string Animal::getType(void) const {
    return (this->_type);
}

Animal &Animal::operator=(const Animal &old) {
    _type = old.getType();
    return (*this);
}

void Animal::makeSound() const {
    std::cout << _type << " Animal is making a sound: NO Sound" << std::endl;
}