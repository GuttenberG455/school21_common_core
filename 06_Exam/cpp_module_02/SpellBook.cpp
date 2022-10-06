
#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {
    std::map<std::string, ASpell *>::iterator it_begin = this->spells_book.begin();
    std::map<std::string, ASpell *>::iterator it_end = this->spells_book.end();

    while (it_begin != it_end) {
        delete it_begin->second;
        ++it_begin;
    }
    this->spells_book.clear();
}

void SpellBook::learnSpell(ASpell *spell_ptr) {
    if (spell_ptr) {
        spells_book.insert(std::pair<std::string, ASpell *>(spell_ptr->getName(), spell_ptr->clone()));
    }
}

void SpellBook::forgetSpell(const std::string &spell_name) {
    std::map<std::string, ASpell *>::iterator it = spells_book.find(spell_name);
    if (it != spells_book.end()) {
        delete it->second;
    }
    spells_book.erase(spell_name);
}

ASpell *SpellBook::createSpell(const std::string &spell_name) {
    std::map<std::string, ASpell *>::iterator it = spells_book.find(spell_name);
    if (it != spells_book.end()) {
        return spells_book[spell_name];
    }
    return NULL;
}
