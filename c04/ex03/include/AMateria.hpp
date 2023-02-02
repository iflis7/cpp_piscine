#pragma once
#include "ICharacter.hpp"

#include <string>
#include <iostream>

/**
 * @brief Base class for all materia
 * 
 */
class AMateria
{
protected:
    std::string _type;

public:
    AMateria();
    AMateria(std::string const &_type);
    AMateria(const AMateria &other);

    AMateria &operator=(const AMateria &rhs);

    virtual ~AMateria();

    std::string const &getType() const; // Returns the materia type
    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target);

}