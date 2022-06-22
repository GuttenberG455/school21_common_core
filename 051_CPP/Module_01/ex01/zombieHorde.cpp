
#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
    if (N <= 0)
        return NULL;
    Zombie *Horde = new Zombie[N];
    for (int i = 0; i < N; i++) {
        std::string z_name = name + std::to_string(i);
        Horde[i] = Zombie(z_name);
    }
    return Horde;
}
