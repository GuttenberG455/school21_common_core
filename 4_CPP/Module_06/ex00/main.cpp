
#include "Converter.hpp"

int main(int argc, char **argv) {

    if (argc != 2) {
        std::cerr << "Error! Wrong amount of arguments. (Usage ./convert <literal>)" << std::endl;
        return (1);
    }
    Converter converter(argv[1]);

    converter.print();

    return (0);
}