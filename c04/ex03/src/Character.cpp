#include "../include/Character.hpp"
#include "../include/AMateria.hpp"

/**
 * @brief Construct a new Character:: Character object
 *
 * @param name The name of the character
 */
Character::Character(const std::string &name)
    : _name(name)
{
    for (int i = 0; i < 4; i++)
        this->_materia[i] = NULL;
}

/**
 * @brief Construct a new Character:: Character object
 *
 * @param other
 */
Character::Character(const Character &other)
    : _name(other._name)
{
    for (int i = 0; i < 4; i++)
        this->_materia[i] = (other._materia[i]) ? other._materia[i]->clone() : NULL;
}

Character &Character::operator=(const Character &rhs)
{
    if (this != &rhs)
    {
        this->~Character();
        this->_name = rhs._name;
        for (int i = 0; i < 4; i++)
            this->_materia[i] = (rhs._materia[i]) ? rhs._materia[i]->clone() : NULL;
    }
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
        if (this->_materia[i] != NULL)
            delete this->_materia[i];
}

const std::string &Character::getName() const
{
    return this->_name;
}

void Character::equip(AMateria *m)
{
    if (m)
    {
        for (int i = 0; i < 4; i++)
        {
            if (!this->_materia[i])
            {
                this->_materia[i] = m;
                break;
            }
        }
    }
}

void Character::unequip(int index)
{
    if (index >= 0 && index <= 3)
        this->_materia[index] = NULL;
}

void Character::use(int index, ICharacter &target)
{
    if (index >= 0 && index <= 3 && this->_materia[index])
        this->_materia[index]->use(target);
}