
#ifndef CONVERTER_HPP
#define CONVERTER_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <cctype>
# include <cmath>

# define CHAR_TYPE 0
# define INT_TYPE 1
# define FLOAT_TYPE 2
# define DOUBLE_TYPE 3
# define INVALID_TYPE 4

# define NO_PSEUDO 0
# define INF_PSEUDO 1
# define MINF_PSEUDO 2
# define NAN_PSEUDO 3

class Converter {
private:
    std::string _input;
    int _type;
    int _pseudo;
    char _charConv;
    int _intConv;
    float _floatConv;
    double _doubleConv;

    int parseInput();
    void printPseudo();
    void printAll();
    void convertAll();
    int checkEnding();
public:
    Converter(char *argv);
    Converter(Converter const &old);
    ~Converter();

    std::string getInput(void);

    Converter &operator=(Converter const &old);

    void print(void);
};


#endif
