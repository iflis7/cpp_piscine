#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

/**
 * @brief The HumanB class
 *
 */
class HumanB
{

private:
    std::string _name;
    Weapon *_weapon;
    // std::auto_ptr<Weapon> _weapon;  // Deprecated in C++11 but could be used with C++98

public:
    HumanB(std::string name);                      // Use constructor, incase the weapon is not set at the time of creation use _weapon(NULL)
    HumanB(std::string name, Weapon *weapon_type); // Use constructor, incase the weapon is set at the time of creation
    ~HumanB(void);

    void attack(void) const;
    void setWeapon(Weapon &weapon_type);
};

#endif
