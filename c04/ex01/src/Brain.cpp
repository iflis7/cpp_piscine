#include "../include/Brain.hpp"

/**
 * @brief Construct a new Brain:: Brain object
 * 
 */
Brain::Brain()
{
	const std::string examples[] = {
		"I want to sleep",
		"I want food",
		"I want pets",
		"I want to go for a walk",
		"I want water",
		"I want a treat"
	};
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = examples[rand() % (sizeof(examples) / sizeof(std::string))];
	std::cout << "Brain(void) constructor called" << std::endl;
}

/**
 * @brief Construct a new Brain:: Brain object
 * 
 * @param copy The boject to copy
 */
Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructor called" << std::endl;
		for (int i = 0; i < 100; i++)
		this->_ideas[i] = other._ideas[i];
}

/**
 * @brief Copy the object
 * 
 * @param src The src object
 * @return Brain& The object returned
 */
Brain &Brain::operator=(const Brain &rhs)
{
	std::cout << "Brain assignation operator called" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = rhs._ideas[i];
	}
	return *this;
}

/**
 * @brief Destroy the Brain:: Brain object
 * 
 */
Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

<<<<<<< HEAD
const std::string Brain::getIdea(int index) const
{
	return this->_ideas[index];
}
=======
// const std::string& Brain::getIdea(int index) const
// {
// 	return this->_ideas[index];
// }
>>>>>>> ad1befb088b1786556af918d454ee3a8ca9d1dfc
