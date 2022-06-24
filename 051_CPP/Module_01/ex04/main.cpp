#include <string>
#include <iostream>

#include "Sed.h"

int main(int argc, char **argv)
{
    if (argc != 4) {
        std::cerr << "Error!\nWrong amount of arguments" << std::endl;
        return 1;
    }
    Sed::replace(argv[1], argv[2], argv[3]);
    return 0;
}
