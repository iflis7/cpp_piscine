#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

// Header-protection
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
	DiamondTrap();
	DiamondTrap(const DiamondTrap &copy);
	DiamondTrap(std::string name);
	DiamondTrap &operator=(const DiamondTrap &src);
	virtual ~DiamondTrap();

	void attack(const std::string &target);
	void whoAmI(void);
};

#endif
