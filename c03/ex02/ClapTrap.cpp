#include "ClapTrap.hpp"

/**
 * @brief Construct a new Clap Trap:: Clap Trap object
 *
 */
ClapTrap::ClapTrap() : _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "Default ClapTrap Constructor Called!" << std::endl;
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

/**
 * @brief Attack the target
 *
 * @param string target: The target to attack
 */
void ClapTrap::attack(std::string const &target)
{
    if (this->_energyPoints > 0)
    {
        std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
        this->_energyPoints--;
    }
    else
    {
        std::cout << "ClapTrap " << this->_name << " has no energy points left!" << std::endl;
    }
}

/**
 * @brief Take damage
 *
 * @param unsigned int amount: The amount of damage to take
 */
void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoints > 0)
    {
        std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
        this->_hitPoints -= amount;
    }
    else
    {
        std::cout << "ClapTrap " << this->_name << " has no hit points left!" << std::endl;
    }
}

/**
 * @brief Be repaired
 *
 * @param unsigned int amount: The amount of hit points to repair
 */
void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_hitPoints > 0 || this->_energyPoints > 0)
    {
        std::cout << "ClapTrap " << this->_name << " repairs " << amount << " points of damage!" << std::endl;
        this->_hitPoints += amount;
        this->_energyPoints--;
    }
    else
    {
        std::cout << "ClapTrap " << this->_name << " has no hit points left!" << std::endl;
    }
}
