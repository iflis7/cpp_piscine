#include "HumanB.hpp"

/**
 * @brief Construct a new Human B:: Human B object
 *
 * @param name The name of the human
 */
HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
}

/**
 * @brief Construct a new Human B:: Human B object
 *
 * @param name The name of the human
 * @param weapon_type The weapon of the human
 */
HumanB::HumanB(std::string name, Weapon *weapon_type) : _name(name), _weapon(weapon_type)
{
}

/**
 * @brief Destroy the Human B:: Human B object
 *
 */
HumanB::~HumanB(void)
{
}

/**
 * @brief Printes attacks with the weapon of the human
 *
 */
void HumanB::attack(void) const
{
    if (!_weapon)
        std::cout << this->_name << " is unarmed and cannot attack" << std::endl;
    else
        std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

/**
 * @brief Set the Weapon object
 *
 * @param weapon_type The weapon of the human
 */
void HumanB::setWeapon(Weapon &weapon_type)
{
    this->_weapon = &weapon_type;
}
