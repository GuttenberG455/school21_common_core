
#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell {
protected:
    std::string name;
    std::string effects;

public:
    ASpell();
    ASpell(std::string const &name, std::string const &effects);
    ASpell(ASpell const &old);
    virtual ~ASpell() ;

    ASpell &operator=(ASpell const &other);
    std::string const &getName(void) const;
    std::string const &getEffects(void) const;

    void launch(ATarget const &target_ref) const;

    virtual ASpell *clone() const = 0;
};


#endif