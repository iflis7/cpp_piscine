#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#pragma once
#include "AMateria.hpp"
#include <string>

/**
 * @brief Interface for a materia source
 * 
 */
class IMateriaSource
{
public:
    virtual ~IMateriaSource(){};
    virtual void learnMateria(AMateria *m) = 0;
    virtual AMateria *createMateria(const std::string &type) = 0;
};

#endif
