#include "../include/Cure.hpp"

/**
 * @brief Construct a new Cure:: Cure object
 *
 */
Cure::Cure()
    : AMateria("cure")
{
}

/**
 * @brief Construct a new Cure:: Cure object
 *
 * @param other
 */
Cure::Cure(const Cure &other)
    : AMateria(other)
{
}

/**
 * @brief Overload the = operator
 *
 * @param other
 * @return Cure&
 */
Cure &Cure::operator=(const Cure &other)
{
    this->AMateria::operator=(other);
    return *this;
}

/**
 * @brief Destroy the Cure:: Cure object
 *
 */
Cure::~Cure()
{
}

/**
 * @brief Applyes a cure on a given Character
 *
 * @param target The Character to apply it on
 */
void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

/**
 * @brief Creates a new Cure Materia
 *
 * @return AMateria*
 */
AMateria *Cure::clone() const
{
    return new Cure(*this);
}
