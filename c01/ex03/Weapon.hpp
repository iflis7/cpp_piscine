#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

/**
 * @brief The Weapon class
 *
 */
class Weapon
{
private:
    std::string _type;

public:
    Weapon(std::string type);
    ~Weapon();
    const std::string &getType();
    void setType(std::string type);
};

#endif