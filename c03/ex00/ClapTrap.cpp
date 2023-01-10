#include "ClapTrap.hpp"

/**
 * @brief Construct a new Clap Trap:: Clap Trap object
 *
 */
ClapTrap::ClapTrap()
{
    std::cout << "Default Constructor Called!" << std::endl;
}

/**
 * @brief Destroy the Clap Trap:: Clap Trap object
 *
 * @param string name: The name of the ClpaTrap
 * @return ClapTrap& The instance created
 */
ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << this->_name << " created" << std::endl;
}

/**
 * @brief Destroy the Clap Trap:: Clap Trap object
 *
 */
ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->_name << " destroyed" << std::endl;
}


