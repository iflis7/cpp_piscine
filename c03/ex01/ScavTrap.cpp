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

/**
 * @brief Destroy the Scav Trap:: Scav Trap object
 *
 */
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Deconstructor for " << this->_name << " called" << std::endl;
}

/**
 * @brief Attack the target
 *
 * @param string target: The target to attack
 */
void ScavTrap::attack(const std::string &target)
{
    std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

/**
 * @brief Guard the gate
 *
 */
void ScavTrap::guardGate()
{
    if (this->_guardeMode == false)
    {
        this->_guardeMode = true;
        std::cout << "ScavTrap " << this->_name << " is now guarding the gate." << std::endl;
    }
    else
        std::cout << "\033[33mScavTrap " << this->_name << " is already guarding the gate.\033[0m" << std::endl;
}
