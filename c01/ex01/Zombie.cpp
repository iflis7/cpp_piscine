#include "Zombie.hpp"

/**
 * @brief Construct a new Zombie:: Zombie object Default constructor
 *
 */
Zombie::Zombie(void)
{
}

/**
 * @brief Construct a new Zombie:: Zombie object
 *
 * @param name  The name of the Zombie
 */
Zombie::Zombie(std::string name)
{
    this->_name = name;
}

/**
 * @brief Destroy the Zombie:: Zombie object
 *
 */
Zombie::~Zombie(void)
{
    std::cout << this->_name << ": is dead..." << std::endl;
}

/**
 * @brief Announce the Zombie
 *
 */
void Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
