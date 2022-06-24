
#include "string"
#include <iostream>
#include <fstream>

#ifndef SED_H
#define SED_H


class Sed {
public:
    Sed();
    ~Sed();

    static void replace(std::string const &filename, char *old_str, char *new_str);
};


#endif //SED_H
