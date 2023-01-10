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
    ~FragTrap();

    void highFivesGuys();
};

#endif
