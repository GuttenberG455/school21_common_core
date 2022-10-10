
#include "Sed.h"

Sed::Sed() {}

Sed::~Sed() {}

void Sed::replace(const std::string &filename, char *old_str, char *new_str) {
    std::string line;
    std::ifstream input;
    std::ofstream output;

    input.open(filename);
    if (!input) {
        std::cerr << "Error\nCouldn't open the input file" << std::endl;
        return;
    }
    output.open(filename + ".replace", std::ios::trunc);
    if (!output) {
        input.close();
        std::cerr << "Error\nCouldn't open the output file" << std::endl;
        return;
    }

    while (std::getline(input, line)) {
        size_t n = strlen(old_str);
        size_t pos = line.find(old_str);

        while (pos != std::string::npos) {
            line.erase(pos, n);
            line.insert(pos, new_str);
            pos += strlen(new_str);
            pos = line.find(old_str, pos, n);
        }
        output << line;
        if (!input.eof())
            output << std::endl;
    }
    input.close();
    output.close();
}