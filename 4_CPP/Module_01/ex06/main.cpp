#include <string>
#include <iostream>

#include "Harl.h"

int main(int argc, char **argv)
{
    Harl harl;

    if (argc != 2) {
        std::cerr << "Error!\nWrong amount of arguments" << std::endl;
        return 1;
    }
    harl.complain(argv[1]);
    return 0;
}
