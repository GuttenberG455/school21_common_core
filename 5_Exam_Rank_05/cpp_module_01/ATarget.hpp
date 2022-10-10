
#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget {
private:
    std::string type;

public:
    ATarget();
    ATarget(std::string const &type);
    ATarget(ATarget const &old);
    virtual ~ATarget() ;

    ATarget &operator=(ATarget const &other);
    std::string const &getType(void) const;

    void getHitBySpell(ASpell const &spell) const;

    virtual ATarget *clone(void) const = 0;

};


#endif