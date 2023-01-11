#ifndef ANIMAL_HPP
# define ANIMAL_HPP

// Header-protection
# pragma once

# include <iostream>
# include <string>

/**
 * @brief Animal class
 *
 */
class Animal
{
  protected:
	std::string _type;

  public:
	Animal();
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);
	virtual ~Animal();

	virtual void makeSound() const = 0;
	std::string getType() const;
	void setType(std::string type);
};

#endif
