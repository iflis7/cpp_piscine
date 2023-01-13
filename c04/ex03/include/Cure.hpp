#ifndef CURE_HPP
#define CURE_HPP

#pragma once

#include "AMateria.hpp"

/**
 * @brief Cure class
 * 
 */
class Cure : public AMateria
{
public:
    // Constructors
    Cure();
    Cure(const Cure &other);

    // Assignment operator overload
    Cure &operator=(const Cure &rhs);

    // Destructor
    ~Cure();

    AMateria *clone() const;
    void use(ICharacter &target);
};

#endif
