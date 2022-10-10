
#include "Weapon.hpp"

Weapon::Weapon(std::string type) :_type(type) {}

Weapon::~Weapon() {}

const std::string &Weapon::getType() {
    return this->_type;
}

void Weapon::setType(const std::string type) {
    this->_type = type;
}
