
#include "../include/DiamondTrap.hpp"

/**
 * @brief Construct a new Diamond Trap:: Diamond Trap object
 *
 */
DiamondTrap::DiamondTrap() : ClapTrap("defaultDT_clap_trap")
{
	this->_name = "defaultDT";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap Default Constructor called" << std::endl;
}

/**
 * @brief Construct a new Diamond Trap:: Diamond Trap object
 *
 * @param copy
 */
DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	*this = copy;
	std::cout << "DiamondTrap Copy Constructor called" << std::endl;
}

/**
 * @brief Construct a new Diamond Trap:: Diamond Trap object
 *
 * @param name The name of the DiamondTrap
 */
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_trap")
{
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap Constructor for the name " << this->_name << " called" << std::endl;
}

/**
 * @brief Copy the Diamond Trap:: Diamond Trap object
 *
 * @param src The DiamondTrap to copy
 * @return DiamondTrap& The object to return
 */
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src)
{
	std::cout << "DiamondTrap Assignation operator called" << std::endl;
	this->_name = src._name + "_clap_trap";
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	return *this;
}

/**
 * @brief Destroy the Diamond Trap:: Diamond Trap object
 *
 */
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Deconstructor for " << this->_name << " called" << std::endl;
}

/**
 * @brief Attack the target
 *
 * @param target The target to attack
 */
void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

/**
 * @brief Displays both its name and its ClapTrap name
 *
 */
void DiamondTrap::whoAmI(void)
{
	std::cout << "Hello i am a DiamondTrap named " << this->_name
			  << " and i am originated from the ClapTrap named " << ClapTrap::_name << "." << std::endl;
}
