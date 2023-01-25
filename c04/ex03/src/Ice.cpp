#include "../include/Ice.hpp"

/**
 * @brief Construct a new Ice:: Ice object
 *
 */
Ice::Ice() : AMateria("ice")
{
}

/**
 * @brief Construct a new Ice:: Ice object
 *
 * @param other The rhs obj
 */
Ice::Ice(const Ice &other) : AMateria(other)
{
}

/**
 * @brief Operator Overloading
 * 
 * @param rhs The right hand side obj
 * @return Ice& the address of the object to return
 */
Ice &Ice::operator=(const Ice &rhs)
{
    this->AMateria::operator=(rhs);
    return *this;
}

/**
 * @brief Destroy the Ice:: Ice object
 *
 */
Ice::~Ice()
{
}

/**
 * @brief Applyes a Ice on a given Character
 *
 * @param target The Character to apply it on
 */
void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

/**
 * @brief Creates a new Ice Materia
 *
 * @return AMateria*
 */
AMateria *Ice::clone() const
{
    return new Ice(*this);
}
