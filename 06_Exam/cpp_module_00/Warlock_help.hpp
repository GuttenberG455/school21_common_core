
#ifndef WARLOCK_HELP_HPP
#define WARLOCK_HELP_HPP

#include "iostream"

class Warlock {
private:
    std::string name;
    std::string title;

public:
    Warlock(std::string name, std::string title);
    ~Warlock();

    std::string const &getName(void) const;
    std::string const &getTitle(void) const;
    void setTitle(std::string title);

    void introduce() const;
};

#endif
