#include "../include/WrongCat.hpp"

/**
 * @brief Construct a new Wrong Cat:: Wrong Cat object
 * 
 */
WrongCat::WrongCat() : WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout << "WrongCat Default Constructor called" << std::endl;
}

/**
 * @brief Construct a new Wrong Cat:: Wrong Cat object
 * 
 * @param copy The boject to copy
 */
WrongCat::WrongCat(const WrongCat &copy)
	: WrongAnimal()
{
	std::cout << "WrongCat Copy Constructor called" << std::endl;
	*this = copy;
}

/**
 * @brief Destroy the Wrong Cat:: Wrong Cat object
 * 
 */
WrongCat::~WrongCat()
{
	std::cout << "WrongCat Deconstructor called" << std::endl;
}

/**
 * @brief Copy the object
 * 
 * @param src The src object
 * @return WrongCat& The object returned
 */
WrongCat &WrongCat::operator=(const WrongCat &src)
{
	std::cout << "WrongCat Assignation operator called" << std::endl;
	if (this == &src)
		return (*this);
	this->_type = src._type;
	return (*this);
}

/**
 * @brief Make sound method
 * 
 */
void WrongCat::makeSound(void) const
{
	std::cout << this->getType() << " says: **WrongCat sounds**" << std::endl;
}
