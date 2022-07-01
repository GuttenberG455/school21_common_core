
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {

}

DiamondTrap::DiamondTrap(std::string name) {
    std::cout << "New DiamondTrap '" << name << "' constructed" << std::endl;
    this->_name = name;
    this->ClapTrap::_name = name + "_clap_name";
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = 50; // TODO I am here now
    this->_attackDamage = 20;
}

DiamondTrap::DiamondTrap(DiamondTrap const &old) :
        ClapTrap(clap), ScavTrap(clap.name), FragTrap(clap.name) {
    this->name = clap.name;
    this->hitpoints = clap.hitpoints;
    this->energy = clap.energy;
    this->attack_damage = clap.attack_damage;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap '" << _name << "' was destructed" << std::endl
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &old) {
    this->_name = old._name;
    this->_hitPoints = old._hitPoints;
    this->_energyPoints = old._energyPoints;
    this->_attackDamage = old._attackDamage;

    return (*this);
}

void DiamondTrap::attack(const int &target) {
    this->ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void) {
    std::cout << "My Diamond name is: " << _name << " and my Clap name is: " << this->ClapTrap::_name << std::endl;
}