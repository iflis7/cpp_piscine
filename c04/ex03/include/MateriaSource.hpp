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
public:
    // Constructors
    MateriaSource();
    MateriaSource(const MateriaSource &other);

    // Assignment operator overload
    MateriaSource &operator=(const MateriaSource &rhs);

    // Destructor
    ~MateriaSource();

    void learnMateria(AMateria *m);
    AMateria *createMateria(const std::string &type);

private:
    AMateria *_materia[4];
};

#endif
