
#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::ASpell(std::string const &name, std::string const &effects) {
    this->name = name;
    this->effects = effects;
}

ASpell::ASpell(const ASpell &old) {
    this->name = old.name;
    this->effects = old.effects;
}

ASpell &ASpell::operator=(ASpell const &other)
{
    this->name = other.name;
    this->effects = other.effects;
    return (*this);
}

ASpell::~ASpell() {}

std::string const &ASpell::getName() const {
    return this->name;
}

std::string const &ASpell::getEffects() const {
    return this->effects;
}

void ASpell::launch(const ATarget &target) {
    target->getHitBySpell(*this);
}

