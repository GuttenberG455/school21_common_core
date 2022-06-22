//
// Created by Manhack Jacqualine on 6/22/22.
//

#ifndef MODULE_01_WEAPON_HPP
#define MODULE_01_WEAPON_HPP

#include <iostream>
#include <string>


class Weapon{
private:
    std::string _type;

public:
    Weapon(std::string);
    virtual ~Weapon();

    std::string getType();
    void setType(std::string type);
};


#endif //MODULE_01_WEAPON_HPP
