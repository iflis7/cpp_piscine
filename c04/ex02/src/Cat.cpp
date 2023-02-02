#include "../include/Cat.hpp"

/**
 * @brief Construct a new Cat:: Cat object
 *
 */
Cat::Cat()
	: AAnimal()
{
	this->_type = "Cat";
	this->_brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

/**
 * @brief Construct a new Cat:: Cat object
 *
 * @param other
 */
Cat::Cat(const Cat &other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = other;
}

/**
 * @brief Construct by assignment the object Overload
 *
 * @param other The rsh
 * @return Cat& The obj returned
 */
Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat Assignation operator called" << std::endl;
	this->_type = other._type;
	this->_brain = new Brain(*other._brain);
	return (*this);
}

/**
 * @brief Destroy the Cat:: Cat object
 *
 */
Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Cat destructor called" << std::endl;
}

/**
 * @brief Make sound method
 *
 */
void Cat::makeSound() const
{
	std::cout << getType() << " Miaous!" << std::endl;
}
