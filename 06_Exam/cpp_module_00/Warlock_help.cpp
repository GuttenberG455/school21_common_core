
#include "Warlock_help.hpp"

Warlock::Warlock(std::string name, std::string title) {
    this->name = name;
    this->title = title;
    std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
	    std::cout << name << ": My job here is done!" << std::endl;
 
}

std::string const &Warlock::getName(void) const {
	return (this->name);
}

std::string const &Warlock::getTitle(void) const {
	return (this->title);
}