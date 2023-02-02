#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

// Header-protection
# pragma once

// Includes
# include "Animal.hpp"

/**
 * @brief WrongAnimal class
 * 
 */
class WrongAnimal : public Animal
{
  public:
	// Constructors
	WrongAnimal();
	WrongAnimal(const WrongAnimal &copy);
	WrongAnimal &operator=(const WrongAnimal &src);
	~WrongAnimal();

	// Public Methods
	void makeSound(void) const;
    // std::string getType(void) const;
};

#endif
