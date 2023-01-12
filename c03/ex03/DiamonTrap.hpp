#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#pragma once

// Includes
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

/**
 * @brief DiamondTrap class inheriting from ScavTrap and FragTrap
 * 
 */
class DiamondTrap : public ScavTrap, public FragTrap
{
private:
    std::string _name;

public:
    // Constructors
    DiamondTrap();
    DiamondTrap(const DiamondTrap &copy);
    DiamondTrap(std::string name);

    // Deconstructors
    virtual ~DiamondTrap();

    // Overloaded Operators
    DiamondTrap &operator=(const DiamondTrap &src);

    // Public Methods
    void attack(const std::string &target);
    void whoAmI(void);

};

#endif