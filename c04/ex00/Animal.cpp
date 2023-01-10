#include "Animal.hpp"

/**
 * @brief Construct a new Animal:: Animal object
 *
 */
Animal::Animal()
{
	std::cout << "Animal constructor called" << std::endl;
}

/**
 * @brief Construct a new Animal:: Animal object
 *
 * @param type The type
 */
Animal::Animal(std::string type)
	: _type(type)
{
	std::cout << "Animal constructor called" << std::endl;
}

/**
 * @brief Construct a new Animal:: Animal object
 *
 * @param other
 */
Animal::Animal(const Animal &other)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = other;
}

/**
 * @brief Copy assignment operator
 *
 * @param other
 * @return Animal&
 */
Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal Assignation operator called" << std::endl;
	this->_type = other._type;
	return (*this);
}

/**
 * @brief Destroy the Animal:: Animal object
 *
 */
Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

/**
 * @brief Get the type method
 *
 * @return std::string The type string
 */
std::string Animal::getType() const
{
	return (this->_type);
}

/**
 * @brief Set the type method
 *
 * @param type The type string
 */
void Animal::setType(std::string type)
{
	this->_type = type;
}

/**
 * @brief Make sound method
 *
 */
void Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}
