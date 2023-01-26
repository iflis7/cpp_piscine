
#pragma once
#include "ICharacter.hpp"
#include <iostream>
#include <iomanip>

/**
 * @brief Character class
 *
 */
class Character : public ICharacter
{
private:
    std::string _name;
    AMateria *_materia[4];

public:
    Character(const std::string &name);
    Character(const Character &other);

    // Assignment operator overload
    Character &operator=(const Character &rhs);

    // Destructor
    ~Character();

    const std::string &getName() const;
    void equip(AMateria *m);
    void unequip(int index);
    void use(int idx, ICharacter &target);
};
