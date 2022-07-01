
#include "FragTrap.hpp"

int main() {

    FragTrap frag("Frag");

    std::cout << std::endl;


    frag.attack("Shrek");
    frag.highFivesGuys();
    frag.takeDamage(5);
    frag.beRepaired(3);

    std::cout << std::endl;

    return 0;
}