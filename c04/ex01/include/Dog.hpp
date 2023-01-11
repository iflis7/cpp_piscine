#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

/**
 * @brief Dog class
 *
 */
class Dog : public Animal
{
  public:
	Dog();
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	virtual ~Dog();

	virtual void makeSound() const;
};

#endif
