
#include "HumanA.hpp"

HumanA::HumanA(std::string const &nameRef, Weapon &weaponRef) : _name(nameRef), _weapon(weaponRef) {}

HumanA::~HumanA() {}

void HumanA::attack() {
    std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}