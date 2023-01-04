#include "Weapon.hpp"

/**
 * @brief Construct a new Weapon:: Weapon object
 *
 * @param type The type of the weapon
 */
Weapon::Weapon(std::string type)
{
    this->_type = type;
}

/**
 * @brief Destroy the Weapon:: Weapon object
 *
 */
Weapon::~Weapon()
{
}

/**
 * @brief Get the Type object
 *
 * @return const std::string& The type of the weapon
 */
const std::string &Weapon::getType()
{
    return this->_type;
}

/**
 * @brief Set the Type object
 *
 * @param type The type of the weapon
 */
void Weapon::setType(std::string type)
{
    this->_type = type;
}
