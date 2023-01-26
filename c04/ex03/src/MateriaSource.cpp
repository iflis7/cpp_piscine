#include "../include/MateriaSource.hpp"

/**
 * @brief Construct a new Materia Source:: Materia Source object
 *
 */
MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        this->_materia[i] = NULL;
}

/**
 * @brief Construct a new Materia Source:: Materia Source object
 *
 * @param rhs The obj to copy
 */
MateriaSource::MateriaSource(const MateriaSource &rhs)
{
    for (int i = 0; i < 4; i++)
        this->_materia[i] = (rhs._materia[i]) ? rhs._materia[i]->clone() : NULL;
}

/**
 * @brief Copy assignment constructor
 *
 * @param rhs The obj to copy
 * @return MateriaSource&  The obj to return
 */
MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
    if (this != &rhs)
    {
        this->~MateriaSource();
        for (int i = 0; i < 4; i++)
            this->_materia[i] = (rhs._materia[i]) ? rhs._materia[i]->clone() : NULL;
    }
    return *this;
}

/**
 * @brief Destroy the Materia Source:: Materia Source object
 *
 */
MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        if (this->_materia[i])
            delete this->_materia[i];
}

/**
 * @brief Copies the Materia passed as a parameter and store
 * it in memory so it can be cloned later.
 *
 * @param Mat
 */
void MateriaSource::learnMateria(AMateria *Mat)
{
    if (Mat)
    {
        for (int i = 0; i < 4; i++)
        {
            if (!this->_materia[i])
            {
                this->_materia[i] = Mat;
                break;
            }
        }
    }
}

/**
 * @brief Returns a new Materia. The latter is a copy of the Materia previously learned by
 * the MateriaSource whose type equals the one passed as paramete
 *
 * @param type The Type to assign
 * @return AMateria* The obj
 */
AMateria *MateriaSource::createMateria(const std::string &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_materia[i] && this->_materia[i]->getType() == type)
            return this->_materia[i]->clone();
    }
    return NULL;
}