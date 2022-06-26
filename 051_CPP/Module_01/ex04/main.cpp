
#include "Sed.h"

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Error!\nWrong amount of arguments" << std::endl;
        return 1;
    }
    if (std::string(argv[2]).length() == 0) {
        std::cerr << "Error!\nOld string to replace is empty\n";
        return (1);
    }
    if (std::string(argv[3]).length() == 0) {
        std::cerr << "Error!\nNew string to replace is empty\n";
        return (1);
    }
    Sed::replace(argv[1], argv[2], argv[3]);
    return 0;
}
