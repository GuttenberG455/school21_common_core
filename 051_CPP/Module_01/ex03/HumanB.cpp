
#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : _name(name) { }

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon &weapon) {
    this->_weapon = &weapon;
}

void HumanB::attack() {
    std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}
