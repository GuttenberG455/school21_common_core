
#include "Dog.hpp"

Dog::Dog() {
    _type = "Dog";
    _brain = new Brain(_type);
    std::cout << "Default Dog was created" << std::endl;
}

Dog::Dog(const Dog &old) {
    _type = old._type;
    _brain = new Brain(*old.getBrain());
    std::cout << "Dog was cloned" << std::endl;
}

Dog::~Dog() {
    delete this->_brain;
    std::cout <<  _type << " died. What a pity!" << std::endl;
}

Dog& Dog::operator= (const Dog &old) {
    _type = old._type;
    _brain = new Brain(*old.getBrain());
    std::cout << "Dog was copied" << std::endl;
    return (*this);
}

Brain *Dog::getBrain() const {
    return (this->_brain);
}

void Dog::makeSound() const {
    std::cout <<  _type << " is making a sound: WOOF-WOOF" << std::endl;
}