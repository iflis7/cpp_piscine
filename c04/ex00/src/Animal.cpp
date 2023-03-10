#include "../include/Animal.hpp"

/**
 * @brief Construct a new Animal:: Animal object
 *
 * @param type The type
 */
Animal::Animal() : _type("Animal")
{
	std::cout << "Animal Default Constructor called" << std::endl;
}

/**
 * @brief Construct a new Animal:: Animal object
 *
 * @param other
 */
Animal::Animal(const Animal &other)
{
	*this = other;
	std::cout << "Animal copy constructor called" << std::endl;
}

/**
 * @brief Copy assignment operator
 *
 * @param other
 * @return Animal&
 */
Animal &Animal::operator=(const Animal &other)
{
	this->_type = other._type;
	std::cout << "Animal Assignation operator called" << std::endl;
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
 * @brief Make sound method
 *
 */
void Animal::makeSound() const
{
	std::cout << "This animal doesn't make any sound." << std::endl;
}
