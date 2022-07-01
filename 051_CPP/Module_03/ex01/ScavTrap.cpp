
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
    std::cout << "New ScavTrap 'Default ScavTrap' constructed" << std::endl;
    this->_name = "Default ScavTrap";
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) {
    std::cout << "New ScavTrap '" << name << "' constructed" << std::endl;
    this->_name = name;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &old) {
    std::cout << "ScavTrap '" << old._name << "' was copied" << std::endl;
    this->_name = old._name;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap '" << _name << "' was destructed" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &old) {

    this->_name = old._name;
    this->_hitPoints = old._hitPoints;
    this->_energyPoints = old._energyPoints;
    this->_attackDamage = old._attackDamage;

    return *this;
}

void ScavTrap::attack(const std::string &target) {
    if (_hitPoints > 0 && _energyPoints > 0) {
        std::cout << "ScavTrap '" << _name << "' attacks " << target << ", causing " << _attackDamage
                  << " points of damage." << std::endl;
        _energyPoints--;
    } else if (_energyPoints == 0 && _hitPoints > 0)
        std::cout << "ScavTrap " << this->_name << " can't attack: no energy." << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap '" << _name << "' is guarding the gate." << std::endl;
}