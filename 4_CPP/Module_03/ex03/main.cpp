
#include "DiamondTrap.hpp"

int main() {

    DiamondTrap	a("Becky");
    DiamondTrap	b("Choppy");

    std::cout << std::endl;

    a.attack("Choppy");
    a.takeDamage(700);
    a.beRepaired(3);
    a.highFivesGuys();
    a.guardGate();
    a.whoAmI();

    std::cout << std::endl;

    b.attack("Conor");
    b.takeDamage(30);
    b.beRepaired(10);
    b.highFivesGuys();
    b.guardGate();
    b.whoAmI();

    std::cout << std::endl;

    return 0;
}