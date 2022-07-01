
#include "ScavTrap.hpp"

int main() {

    ScavTrap a;
    ScavTrap b("Kirill Borov");
    ScavTrap c("Vitya Vertushka");

    std::cout << std::endl;

    a.attack("Rogue");
    b.attack("Nalichnik");
    c.attack("Rogue");

    b.takeDamage(30);
    b.takeDamage(80);
    b.takeDamage(5);
    c.takeDamage(42);

    b.attack("somebody");
    c.attack("Klopp");
    c.beRepaired(3);
    c.beRepaired(13);

    std::cout << std::endl;

    return 0;
}