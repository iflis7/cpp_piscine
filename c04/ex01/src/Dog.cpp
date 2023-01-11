#include "../include/Dog.hpp"

/**
 * @brief Construct a new Dog:: Dog object
 *
 */
Dog::Dog()
	: Animal()
{
	this->_type = "Dog";
	this->brain = new Brain();
	std::cout << this->_type << " constructor called" << std::endl;
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
 * @param other The rsh 
 * @return Dog& The obj returned
 */
Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog Assignation operator called" << std::endl;
	this->_type = other._type;
	this->brain = new Brain(*other.brain);
	return (*this);
}

/**
 * @brief Destroy the Dog:: Dog object
 *
 */
Dog::~Dog()
{
	delete this->brain;
	std::cout << this->_type << " destructor called" << std::endl;
}

/**
 * @brief Make sound method
 *
 */
void Dog::makeSound() const
{
	std::cout << getType() << " Barks! " << std::endl;
}
