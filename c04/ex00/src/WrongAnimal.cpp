#include "../include/WrongAnimal.hpp"

/**
 * @brief Construct a new Wrong Animal:: Wrong Animal object
 * 
 */
WrongAnimal::WrongAnimal() // TODO incvestigate more lol!
{
	this->_type = "WrongAnimal";
	std::cout << "WrongAnimal Default Constructor called" << std::endl;
}

/**
 * @brief Construct a new Wrong Animal:: Wrong Animal object
 * 
 * @param copy The boject to copy
 */
WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "WrongAnimal Copy Constructor called" << std::endl;
	*this = copy;
}

/**
 * @brief Destroy the Wrong Animal:: Wrong Animal object
 * 
 */
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Deconstructor called" << std::endl;
}

/**
 * @brief Copy the object
 * 
 * @param src The src object
 * @return WrongAnimal& The obj returned
 */
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
	std::cout << "WrongAnimal Assignation operator called" << std::endl;
	if (this == &src)
		return (*this);
	this->_type = src._type;
	return (*this);
}

/**
 * @brief Make sound method
 * 
 */
void WrongAnimal::makeSound(void) const
{
	std::cout << this->getType() << " says: **WrongAnimal sounds**" << std::endl;
}

// /**
//  * @brief Get the type object
//  * 
//  * @return std::string The type returned
//  */
// std::string WrongAnimal::getType(void) const
// {
// 	return (this->_type);
// }
