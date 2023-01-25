#include "../include/AMateria.hpp"

/**
 * @brief Construct a new AMateria::AMateria object
 *
 * @param type
 */
AMateria::AMateria(std::string const &type)
    : _type(type)
{
}

/**
 * @brief Construct a new AMateria::AMateria object
 *
 * @param other
 */
AMateria::AMateria(const AMateria &other)
    : _type(other._type)
{
}

/**
 * @brief Operator = overload
 *
 * @param rhs
 * @return AMateria&
 */
AMateria &AMateria::operator=(const AMateria &rhs)
{
    if (this != &rhs)
        this->_type = rhs._type;
    return *this;
}

/**
 * @brief Destroy the AMateria::AMateria object
 *
 */
AMateria::~AMateria()
{
}

/**
 * @brief getType getter
 *
 * @return std::string const&
 */
std::string const &AMateria::getType() const
{
    return this->_type;
}

/**
 * @brief Use a Materia on a given Character
 *
 * @param target The Character target
 */
void AMateria::use(ICharacter &target)
{
    (void)target;
}
