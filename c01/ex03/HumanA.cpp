#include "HumanA.hpp"

/**
 * @brief Construct a new Human A:: Human A object
 *
 * @param name The name of the human
 * @param weapon An instance of the Weapon class
 */
HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon)
{
    this->_name = name;
}

/**
 * @brief Destroy the Human A:: Human A object
 *
 */
HumanA::~HumanA()
{
}

/**
 * @brief Printes attacks with the weapon of the human
 *
 */
void HumanA::attack()
{
    std::cout << this->_name << " attacks with his " << this->weapon.getType() << std::endl;
}
