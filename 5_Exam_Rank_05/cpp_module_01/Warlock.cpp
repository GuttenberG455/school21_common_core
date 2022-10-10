#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title) {
    this->name = name;
    this->title = title;
    std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
    std::cout << name << ": My job here is done!" << std::endl;
    std::map<std::string, ASpell *>::iterator it_begin = this->spells.begin();
    std::map<std::string, ASpell *>::iterator it_end = this->spells.end();
    while (it_begin != it_end)
    {
        delete it_begin->second;
        ++it_begin;
    }
    this->spells.clear();

}

std::string const &Warlock::getName(void) const {
    return (this->name);
}

std::string const &Warlock::getTitle(void) const {
    return (this->title);
}

void Warlock::setTitle(std::string const &title) {
    this->title = title;
}

void Warlock::introduce() const {
    std::cout << this->name << ": I am " << this->name << ", " << this->title << "!\n";
}

void Warlock::learnSpell(ASpell *spell_ptr) {
    if (spell_ptr) {
        this->spells.insert(std::pair<std::string, ASpell *>(spell_ptr->getName(), spell_ptr->clone()));
    }
}

void Warlock::forgetSpell(std::string spell_name) {
    std::map<std::string, ASpell *>::iterator it = this->spells.find(spell_name);
    if (it !=  this->spells.end())
        delete it->second;
    this->spells.erase(spell_name);
}

void Warlock::launchSpell(std::string spell_name, ATarget const &target_ref)
{
    ASpell* spell = this->spells[spell_name];
    if (spell)
        spell->launch(target_ref);
}