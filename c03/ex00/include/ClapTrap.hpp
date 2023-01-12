#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

// Header protection
#pragma once

#include <iostream>
#include <string>

/**
 * @brief ClapTrap class declaration
 *
 */
class ClapTrap
{
private:
    std::string _name;
    int _hitPoints;
    int _energyPoints;
    int _attackDamage;

public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &other);
    ClapTrap &operator=(const ClapTrap &other);
    ~ClapTrap();

    void attack(std::string const &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif
