#include "../include/Dog.hpp"

/**
 * @brief Construct a new Dog:: Dog object
 *
 */
Dog::Dog()
	: Animal()
{
	this->_type = "Dog";
	std::cout << this->_type << " constructor called" << std::endl;
}

/**
 * @brief Construct a new Dog:: Dog object
 *
 * @param other
 */
Dog::Dog(const Dog &other)
{
	*this = other;
	std::cout << "Dog copy constructor called" << std::endl;
}

/**
 * @brief Construct by assignment the object Overload
 *
 * @param other The rsh 
 * @return Dog& The obj returned
 */
Dog &Dog::operator=(const Dog &other)
{
	this->_type = other._type;
	std::cout << "Dog Assignation operator called" << std::endl;
	return (*this);
}

/**
 * @brief Destroy the Dog:: Dog object
 *
 */
Dog::~Dog()
{
	std::cout << this->_type << " destructor called" << std::endl;
}

/**
 * @brief Make sound method
 *
 */
void Dog::makeSound() const
{
	std::cout << this->getType() << " Barks! " << std::endl;
}
