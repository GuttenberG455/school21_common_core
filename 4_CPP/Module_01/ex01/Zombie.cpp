
#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {
}


Zombie::~Zombie() {
    std::cout << _name << " is dead (finally)" << std::endl;
}

void Zombie::set_name(std::string name) {
    this->_name = name;
}

void Zombie::announce() {
    std::cout << _name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
