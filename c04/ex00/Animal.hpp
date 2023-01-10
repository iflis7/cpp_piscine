#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

/**
 * @brief Animal class
 *
 */
class Animal
{
protected:
    std::string _type;

public:
    Animal();
    Animal(std::string type);
    Animal(const Animal &other);
    Animal &operator=(const Animal &other);
    virtual ~Animal();

    virtual void makeSound() const;
    std::string getType() const;
    void setType(std::string type);
};

#endif
