#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

// Header-protection
#pragma once

// Includes
#include <string>
#include <iostream>

/**
 * @brief ClapTrap class declaration
 *
 */
class ClapTrap
{
	protected:
		std::string _name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;

	public:
		ClapTrap();
		ClapTrap(const ClapTrap &copy);
		ClapTrap(std::string name);
		ClapTrap &operator=(const ClapTrap &src);
		virtual ~ClapTrap();

		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
