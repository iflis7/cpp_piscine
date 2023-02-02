#include "../include/AAnimal.hpp"

/**
 * @brief Construct a new AAnimal:: AAnimal object
 *
 * @param type The type
 */
AAnimal::AAnimal() : _type("default")
{
	std::cout << "AAnimal Default Constructor called" << std::endl;
}

/**
 * @brief Construct a new AAnimal:: AAnimal object
 *
 * @param other
 */
AAnimal::AAnimal(const AAnimal &other)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = other;
}

/**
 * @brief Copy assignment operator
 *
 * @param other
 * @return AAnimal&
 */
AAnimal &AAnimal::operator=(const AAnimal &other)
{
	std::cout << "AAnimal Assignation operator called" << std::endl;
	this->_type = other._type;
	return (*this);
}

/**
 * @brief Destroy the AAnimal:: AAnimal object
 *
 */
AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

/**
 * @brief Get the type method
 *
 * @return std::string The type string
 */
std::string AAnimal::getType() const
{
	return (this->_type);
}

/**
 * @brief Make sound method
 *
 */
void AAnimal::makeSound() const
{
	std::cout << "This animal doesn't make any sound." << std::endl;
}
