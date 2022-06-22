
#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main()
{
    Zombie zombie1("Jiji");
    zombie1.announce();

    Zombie *zombie2 = newZombie("Bobo");
    zombie2->announce();

    randomChump("Gogi");
    randomChump("Bobby");

    delete zombie2;

    return 0;
}