
#include "../include/FragTrap.hpp"

/**
 * @brief Construct a new Frag Trap:: Frag Trap object
 *
 */
FragTrap::FragTrap() : ClapTrap()
{
	if (this->_hitPoints == 10)
		this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap Default Constructor for " << this->_name << " called" << std::endl;
}

/**
 * @brief Construct a new Frag Trap:: Frag Trap object
 *
 * @param string name: The name of the FragTrap
 * @return FragTrap& The instance created
 */
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	// this->_name = name;
	if (this->_hitPoints == 10)
		this->_hitPoints = 100;
	this->_energyPoints = 100;
	if (this->_attackDamage == 0)
		this->_attackDamage = 30;
	std::cout << "FragTrap Constructor for the name " << this->_name << " called" << std::endl;
}

/**
 * @brief Construct a new Frag Trap:: Frag Trap object
 *
 * @param copy The copy to make
 */
FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	std::cout << "FragTrap Copy Constructor called" << std::endl;
}

/**
 * @brief Copy the Frag Trap:: Frag Trap object
 *
 * @param src the FragTrap to copy
 * @return FragTrap& The obj to return
 */
FragTrap &FragTrap::operator=(const FragTrap &src)
{
	std::cout << "FragTrap Assignation operator called" << std::endl;
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	return *this;
}

/**
 * @brief Destroy the Frag Trap:: Frag Trap object
 *
 */
FragTrap::~FragTrap()
{
	std::cout << "FragTrap Deconstructor for " << this->_name << " called" << std::endl;
}

/**
 * @brief High five the target
 *
 * @param string target: The target to high five
 */
void FragTrap::highFiveGuys(void)
{
	std::cout << "FragTrap " << this->_name << ": You want a high five?\n\t*WHAMM*\nHere you go." << std::endl;
}
