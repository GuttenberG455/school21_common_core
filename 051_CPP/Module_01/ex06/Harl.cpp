
#include "Harl.h"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug() {
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger. I really do!"
              << std::endl;
}

void Harl::info() {
    std::cout
            << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
            << std::endl;
}

void Harl::warning() {
    std::cout
            << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
            << std::endl;
}

void Harl::error() {
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

int getLvl(std::string const &l) {
    std::string const pool[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; ++i)
        if (pool[i] == l)
            return i;
    return -1;
}

void Harl::complain(std::string level) {

    switch (getLvl(level)) {
        case 0:
            this->debug();
        case 1:
            this->info();
        case 2:
            this->warning();
        case 3:
            this->error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
}