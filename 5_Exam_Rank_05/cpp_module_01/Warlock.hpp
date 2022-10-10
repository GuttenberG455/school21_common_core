
#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <map>
#include "Dummy.hpp"
#include "Fwoosh.hpp"

class Warlock {
private:
    std::string name;
    std::string title;
    std::map<std::string, ASpell *> spells;
public:
    Warlock(std::string const &name, std::string const &title);
    ~Warlock();

    std::string const &getName(void) const;
    std::string const &getTitle(void) const;
    void setTitle(std::string const &title);

    void introduce() const;

    void learnSpell(ASpell *spell_ptr);
    void forgetSpell(std::string spell_name);
    void launchSpell(std::string spell_name, ATarget const &target_ref);
};

#endif