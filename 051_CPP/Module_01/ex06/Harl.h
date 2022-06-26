
#ifndef HARL_H
#define HARL_H

#include "iostream"

class Harl {
private:

    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

    enum lvl {
        DEBUG = 1,
        INFO,
        WARNING,
        ERROR,
    };

public:
    Harl();
    ~Harl();

    void complain(std::string level);
};


#endif