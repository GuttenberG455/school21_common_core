
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(ScavTrap const &old);
    ~ScavTrap();

    ScavTrap &operator=(ScavTrap const &old);
    virtual void	attack( std::string const &target );
    void guardGate();
};


#endif
