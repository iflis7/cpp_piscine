#include "../include/ScavTrap.hpp"

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
 * @brief Construct a new Scav Trap:: Scav Trap object
 *
 * @param copy The copy to make
 */
ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
    this->_guardeMode = copy._guardeMode;
    std::cout << "ScavTrap Copy Constructor called" << std::endl;
}

/**
 * @brief Copy the Scav Trap:: Scav Trap object
 *
 * @param src The ScavTrap to copy
 * @return ScavTrap& The obj to return
 */
ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
    std::cout << "ScavTrap Assignation operator called" << std::endl;
    this->_name = src._name;
    this->_hitPoints = src._hitPoints;
    this->_energyPoints = src._energyPoints;
    this->_attackDamage = src._attackDamage;
    return *this;
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
