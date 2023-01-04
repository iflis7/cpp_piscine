#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{

private:
    std::string _name;
    Weapon *_weapon;

public:
    HumanB(std::string name);
    HumanB(std::string name, Weapon *weapon_type);
    ~HumanB(void);

    void attack(void) const;
    void setWeapon(Weapon &weapon_type);
};

#endif
