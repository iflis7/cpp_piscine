#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

/**
 * @brief Dog class
 *
 */
class Dog : public Animal
{
private:
	Brain *_brain;

public:
	Dog();
	Dog(std::string type);
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	virtual ~Dog();

	Brain *getBrain() const;

	virtual void makeSound() const;
};

#endif
