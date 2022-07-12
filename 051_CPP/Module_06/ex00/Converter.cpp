
#include "Converter.hpp"

Converter::Converter(char *argv) {
    this->_input = std::string(argv);
}

Converter::Converter(const Converter &old) : _input(old._input) {}

Converter::~Converter() {}

std::string Converter::getInput() {
    return (this->_input);
}

Converter &Converter::operator=(const Converter &old) {
    this->_input = old._input;
    return (*this);
}

void Converter::printChar() {
}

void Converter::printInt() {
    std::istringstream iss (this->_input);
    int number;
    iss >> number;
    if (iss.fail()) {
        std::cerr << "ERROR!\n";
        return ;
    }
    std::cout << "char: " << (char)number << std::endl;
    std::cout << "int: " << number << std::endl;
    std::cout << "float: " << number << ".0f" << std::endl;
    std::cout << "double: " << number << ".0" << std::endl;
}

void Converter::printFloat() {
}

void Converter::printDouble() {
}

void Converter::printAll() {
    printInt();
}