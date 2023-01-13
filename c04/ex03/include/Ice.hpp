#ifndef ICE_HPP
#define ICE_HPP

#pragma once

#include "AMateria.hpp"

/**
 * @brief Ice class
 * 
 */
class Ice : public AMateria
{
public:
    // Constructors
    Ice();
    Ice(const Ice &other);

    // Assignment operator overload
    Ice &operator=(const Ice &rhs);

    // Destructor
    ~Ice();

    AMateria *clone() const;
    void use(ICharacter &target);
};

#endif
