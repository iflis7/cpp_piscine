#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

// Header-protection
#pragma once

// Includes
#include "ClapTrap.hpp"

/**
 * @brief FragTrap class declaration
 *
 */
class FragTrap : virtual public ClapTrap
{
private:
public:
	FragTrap();
	FragTrap(const FragTrap &copy);
	FragTrap(std::string name);
	FragTrap &operator=(const FragTrap &src);
	~FragTrap();

	// Public Methods
	void highFiveGuys(void);
};

#endif
