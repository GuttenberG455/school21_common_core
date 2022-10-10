
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
    std::cout << "New ClapTrap 'Default claptrap' constructed" << std::endl;
    this->_name = "Default claptrap";
    this->_hitPoints = 10;
    this->_energyPoints = 10;
    this->_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name) {
    std::cout << "New ClapTrap '" << name << "' constructed" << std::endl;
    this->_name = name;
    this->_hitPoints = 10;
    this->_energyPoints = 10;
    this->_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &old) {
    std::cout << "ClapTrap '" << old._name << "' was copied" << std::endl;
    this->_name = old._name;
    this->_hitPoints = 10;
    this->_energyPoints = 10;
    this->_attackDamage = 0;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap '" << _name << "' was destructed" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &old) {
    this->_name = old._name;
    this->_hitPoints = old._hitPoints;
    this->_energyPoints = old._energyPoints;
    this->_attackDamage = old._attackDamage;

    return (*this);
}

void ClapTrap::attack(const std::string &target) {
    if (_hitPoints > 0 && _energyPoints > 0) {
        std::cout << "ClapTrap '" << _name << "' attacks " << target << ", causing " << _attackDamage
                  << " points of damage." << std::endl;
        _energyPoints--;
    } else if (_energyPoints == 0 && _hitPoints > 0)
        std::cout << "ClapTrap " << this->_name << " can't attack: no energy." << std::endl;
}

void ClapTrap::takeDamage(unsigned int damage) {
    if (_hitPoints > 0) {
        this->_hitPoints -= damage;
        if (this->_hitPoints <= 0) {
            this->_hitPoints = 0;
            std::cout << "ClapTrap " << this->_name << " takes " << damage << " damage and died. RIP!" << std::endl;
        }
        else
            std::cout << "ClapTrap " << this->_name << " takes " << damage << " damage." << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_energyPoints > 0 && _hitPoints > 0) {
        _hitPoints += amount;
        _energyPoints--;
        if (_hitPoints > 10)
            _hitPoints = 10;
        std::cout << "ClapTrap '" << _name << "' was repaired by " << amount << ", and now it has " << _hitPoints
                  << " hit points." << std::endl;
    }
    else if (_energyPoints == 0 && _hitPoints > 0)
        std::cout << "ClapTrap " << this->_name << " cannot be repaired: no energy." << std::endl;
}