#include "ScavTrap.hpp"

/**
 * @brief Construct a new Scav Trap:: Scav Trap object
 *
 */
ScavTrap::ScavTrap() : ClapTrap()
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    this->_guardeMode = false;
}

/**
 * @brief Construct a new Scav Trap:: Scav Trap object
 *
 * @param string name: The name of the ScavTrap
 * @return ScavTrap& The instance created
 */
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    this->_guardeMode = false;
}

