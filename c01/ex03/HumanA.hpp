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
    Weapon &weapon;

public:
    HumanA(std::string name, Weapon &weapon);
    ~HumanA();

    void attack();
};

#endif
