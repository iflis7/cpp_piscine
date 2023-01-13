#include "../include/Brain.hpp"

/**
 * @brief Construct a new Brain:: Brain object
 * 
 */
Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
}

/**
 * @brief Construct a new Brain:: Brain object
 * 
 * @param copy The boject to copy
 */
Brain::Brain(const Brain &copy)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = copy;
}

/**
 * @brief Copy the object
 * 
 * @param src The src object
 * @return Brain& The object returned
 */
Brain &Brain::operator=(const Brain &src)
{
	std::cout << "Brain assignation operator called" << std::endl;
	if (this == &src)
		return (*this);
	return (*this);
}

/**
 * @brief Destroy the Brain:: Brain object
 * 
 */
Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

const std::string& Brain::getIdea(int index) const
{
	return this->_ideas[index];
}