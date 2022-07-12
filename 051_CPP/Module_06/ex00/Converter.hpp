
#ifndef CONVERTER_HPP
#define CONVERTER_HPP

# include <iostream>
# include <sstream>
# include <string>

# include <cctype>
# include <cmath>
# include <limits>

class Converter {
private:
    std::string _input;
public:
    Converter(char *argv);
    Converter(Converter const &old);
    ~Converter();

    std::string getInput(void);

    Converter &operator=(Converter const &old);

    void printChar(void);
    void printInt(void);
    void printFloat(void);
    void printDouble(void);

    void printAll(void);
};


#endif
