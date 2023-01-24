#include "../include/Dog.hpp"

/**
 * @brief Construct a new Dog:: Dog object
 *
 */
Dog::Dog()
	: Animal("Dog"), _brain(new Brain())
{
	std::cout << this->_type << " constructor called" << std::endl;
}

/**
 * @brief Construct a new Dog:: Dog object
 *
 * @param type The type
 */
Dog::Dog(std::string type)
	: Animal(type), _brain(new Brain())
{
	std::cout << this->_type << " constructor called" << std::endl;
}

/**
 * @brief Construct a new Dog:: Dog object
 *
 * @param other
 */
Dog::Dog(const Dog &other) : Animal()
{
	this->_brain = new Brain(*other._brain);
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
	std::cout << "Dog Assignation operator called" << std::endl;
	this->_type = other._type;
	this->_brain = new Brain(*other._brain);
	return (*this);
}

/**
 * @brief Destroy the Dog:: Dog object
 *
 */
Dog::~Dog()
{
	delete this->_brain;
	std::cout << this->_type << " destructor called" << std::endl;
}

/**
 * @brief Get the Brain object
 *
 * @return Brain* The brain
 */
Brain *Dog::getBrain() const
{
	return (this->_brain);
}

/**
 * @brief Make sound method
 *
 */
void Dog::makeSound() const
{
	std::cout << getType() << " Barks! " << std::endl;
}
