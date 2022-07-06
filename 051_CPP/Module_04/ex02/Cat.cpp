
#include "Cat.hpp"

Cat::Cat() {
    _type = "Cat";
    _brain = new Brain(_type);
    std::cout << "Default Cat was created" << std::endl;
}

Cat::Cat(const Cat &old) {
    _type = old.getType();
    _brain = new Brain(*old.getBrain());
    std::cout << "Cat was cloned" << std::endl;
}

Cat::~Cat() {
    delete this->_brain;
    std::cout << _type << " was found dead. RIP!" << std::endl;
}

Cat &Cat::operator=(const Cat &old) {
    _type = old.getType();
    _brain = new Brain(*old.getBrain());
    std::cout << "Cat was copied" << std::endl;
    return (*this);
}

Brain *Cat::getBrain() const {
    return (this->_brain);
}

void Cat::makeSound() const {
    std::cout << _type << " is making a sound: MEOW-MEOW" << std::endl;
}