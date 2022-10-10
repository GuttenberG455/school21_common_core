
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
    std::cout << "New DiamondTrap constructed" << std::endl;
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(std::string name) {
    std::cout << "New DiamondTrap '" << name << "' constructed" << std::endl;
    this->_name = name;
    this->ClapTrap::_name = name + "_clap_name";
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(DiamondTrap const &clap) :
        ClapTrap(clap), ScavTrap(clap._name), FragTrap(clap._name) {
    this->_name = clap._name;
    this->_hitPoints = clap._hitPoints;
    this->_energyPoints = clap._energyPoints;
    this->_attackDamage = clap._attackDamage;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap was destructed" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &old) {
    this->_name = old._name;
    this->_hitPoints = old._hitPoints;
    this->_energyPoints = old._energyPoints;
    this->_attackDamage = old._attackDamage;

    return (*this);
}

void DiamondTrap::attack(const std::string &target) {
    this->ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void) {
    std::cout << "My Diamond name is " << _name << " and my Clap name is " << this->ClapTrap::_name << std::endl;
}