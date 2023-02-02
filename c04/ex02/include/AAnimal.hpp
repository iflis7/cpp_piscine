#ifndef AANIMAL_HPP
# define AANIMAL_HPP

// Header-protection
# pragma once

# include <iostream>
# include <string>

/**
 * @brief AAnimal class
 *
 */
class AAnimal
{
  protected:
	std::string _type;

  public:
	AAnimal();
	AAnimal(const AAnimal &other);
	AAnimal &operator=(const AAnimal &other);
	virtual ~AAnimal();

	virtual void makeSound() const = 0;
	std::string getType() const;
	void setType(std::string type);
};

#endif
