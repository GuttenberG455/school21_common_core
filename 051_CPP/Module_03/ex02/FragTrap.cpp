
#include "FragTrap.hpp"

FragTrap::FragTrap() {
    std::cout << "New FragTrap 'Default FragTrap' constructed" << std::endl;
    this->_name = "Default FragTrap";
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) {
    std::cout << "New FragTrap '" << name << "' constructed" << std::endl;
    this->_name = name;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &old) {
    std::cout << "FragTrap '" << old._name << "' was copied" << std::endl;
    this->_name = old._name;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap '" << _name << "' was destructed" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &old) {

    this->_name = old._name;
    this->_hitPoints = old._hitPoints;
    this->_energyPoints = old._energyPoints;
    this->_attackDamage = old._attackDamage;

    return *this;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << _name << ": High Five!\n";
}