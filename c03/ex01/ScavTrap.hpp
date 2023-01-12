#ifndef SCRAPTRAP_HPP
#define SCRAPTRAP_HPP

// Header protection
#pragma once

#include "ClapTrap.hpp"

/**
 * @brief ScavTrap class declaration
 *
 */
class ScavTrap : public ClapTrap
{
private:
    bool _guardeMode;

public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap &copy);
    ScavTrap &operator=(const ScavTrap &src);
    ~ScavTrap();

    // Overide with a new message
    void attack(const std::string &target);
    void guardGate();
};

#endif