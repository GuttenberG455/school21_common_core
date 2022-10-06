
#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include "ASpell.hpp"
#include <map>

class SpellBook {
private:
    std::map<std::string, ASpell *> spells_book;

    SpellBook(SpellBook const &other);
    SpellBook operator=(SpellBook const &other);
public:
    SpellBook();
    ~SpellBook();

    void learnSpell(ASpell *spell_ptr);
    void forgetSpell(std::string const &spell_name);
    ASpell *createSpell(std::string const &spell_name);
};


#endif