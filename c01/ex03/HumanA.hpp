#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

/**
 * @brief The HumanA class
 *
 */
class HumanA
{
private:
    std::string _name;
    Weapon &_weapon;

public:
    HumanA(std::string name, Weapon &_weapon);
    ~HumanA();

    void attack();
};

#endif
