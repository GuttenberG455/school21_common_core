
#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
protected:
    std::string _ideas[100];

public:
    Brain();
    Brain(std::string type);
    Brain(Brain const &old);
    ~Brain();

    Brain &operator=(Brain const &old);
    void setIdea(std::string const idea);
    std::string getIdea(void);
};


#endif
