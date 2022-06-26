#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

class Zombie {

private:
    std::string _name;

public:
    Zombie(std::string name);
    ~Zombie();

    void announce(void);

};


#endif
