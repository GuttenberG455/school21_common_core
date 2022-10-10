
#include "ClapTrap.hpp"

int main() {

    ClapTrap a;
    ClapTrap b("Rogue");
    ClapTrap c(a);

    std::cout << std::endl;

    a.attack("Rogue");
    b.attack("Nalichnik");
    c.attack("Rogue");
    for (int _ = 0; _ < 10; _++)
        c.attack("Check");

    b.takeDamage(5);
    b.takeDamage(5);
    b.takeDamage(5);
    c.takeDamage(5);

    b.attack("somebody");
    c.attack("Klopp");
    c.beRepaired(3);
    c.beRepaired(13);

    std::cout << std::endl;

    return 0;
}