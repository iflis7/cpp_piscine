#include "Dog.hpp"

/**
 * @brief Construct a new Dog:: Dog object
 *
 */
Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog constructor called" << std::endl;
}

/**
 * @brief Construct a new Dog:: Dog object
 *
 * @param type The type
 */
Dog::Dog(std::string type) : Animal(type)
{
    std::cout << "Dog constructor called" << std::endl;
}

/**
 * @brief Construct a new Dog:: Dog object
 *
 * @param other
 */
Dog::Dog(const Dog &other)
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = other;
}

/**
 * @brief Construct by assignment the object Overload
 *
 * @param other
 * @return Dog&
 */
Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Dog Assignation operator called" << std::endl;
    this->_type = other._type;
    return (*this);
}

/**
 * @brief Destroy the Dog:: Dog object
 *
 */
Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

/**
 * @brief Make sound method
 *
 */
void Dog::makeSound() const
{
    std::cout << "Barks! " << std::endl;
}
