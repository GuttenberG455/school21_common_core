
#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int main() {
    int N = 13;
    Zombie *Horde = zombieHorde(N, "Zombik");
    if (Horde == NULL)
        return (EXIT_FAILURE);
    for (int i = 0; i < N; ++i)
        Horde[i].announce();
    delete[] Horde;
    return 0;
}
