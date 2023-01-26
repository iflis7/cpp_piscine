#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#pragma once
#include "IMateriaSource.hpp"

/**
 * @brief MateriaSource class
 *
 */
class MateriaSource : public IMateriaSource
{
private:
    AMateria *_materia[4];

public:
    // Constructors
    MateriaSource();
    MateriaSource(const MateriaSource &rhs);

    // Assignment operator overload
    MateriaSource &operator=(const MateriaSource &rhs);

    // Destructor
    ~MateriaSource();

    void learnMateria(AMateria *Mat);
    AMateria *createMateria(const std::string &type);
};

#endif
