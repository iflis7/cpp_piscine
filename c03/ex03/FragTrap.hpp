#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

// Header protection
#pragma once

#include "ClapTrap.hpp"

/**
 * @brief FragTrap class declaration
 *
 */
class FragTrap : public ClapTrap
{
public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(const FragTrap &other);
    FragTrap &operator=(const FragTrap &other);
    ~FragTrap();

    void highFivesGuys();
};

#endif
