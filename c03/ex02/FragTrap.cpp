#include "FragTrap.hpp"

/**
 * @brief Construct a new Frag Trap:: Frag Trap object
 *
 */
FragTrap::FragTrap() : ClapTrap()
{
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap default constructor called" << std::endl;
}

/**
 * @brief Construct a new Frag Trap:: Frag Trap object
 *
 * @param string name: The name of the FragTrap
 * @return FragTrap& The instance created
 */
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap " << this->_name << " created" << std::endl;
}

/**
 * @brief Destroy the Frag Trap:: Frag Trap object
 *
 */
FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->_name << " destroyed" << std::endl;
}

/**
 * @brief High five the target
 *
 * @param string target: The target to high five
 */
void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << this->_name << " high fives the guys" << std::endl;
}
