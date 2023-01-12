#ifndef SCRAPTRAP_HPP
#define SCRAPTRAP_HPP

// Header-protection
#pragma once

// Includes
#include "ClapTrap.hpp"

/**
 * @brief ScavTrap class declaration
 *
 */
class ScavTrap : virtual public ClapTrap
{
private:
	bool _guarding_gate;

public:
	ScavTrap();
	ScavTrap(const ScavTrap &copy);
	ScavTrap(std::string name);
	ScavTrap &operator=(const ScavTrap &src);
	~ScavTrap();

	// Public Methods
	void attack(const std::string &target);
	void guardGate(void);
};

#endif
