
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    _type = "WrongAnimal";
    std::cout << "Wrong Animal was created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &old) {
    _type = old.getType();
}

WrongAnimal::~WrongAnimal() {
    std::cout << "Wrong Animal was destructed" << std::endl;
}

std::string WrongAnimal::getType(void) const {
    return (this->_type);
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &old) {
    _type = old.getType();
    return (*this);
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal is making a wrong sound" << std::endl;
}
