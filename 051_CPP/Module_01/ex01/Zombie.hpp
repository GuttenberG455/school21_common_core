
#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

class Zombie {

private:
    std::string  _name;

public:
    Zombie();
    Zombie(std::string name);
    ~Zombie();

    void set_name(std::string name);

    void announce( void );
};


#endif
