//
// Created by Manhack Jacqualine on 7/1/22.
//

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(FragTrap const &old);
    ~FragTrap();

    FragTrap &operator=(FragTrap const &old);
    void highFivesGuys();
};


#endif
