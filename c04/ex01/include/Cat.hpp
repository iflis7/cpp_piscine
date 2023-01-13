#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

/**
 * @brief Cat class
 *
 */
class Cat : public Animal
{
private:
	Brain *_brain;

public:
	Cat();
	Cat(std::string type);
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	virtual ~Cat();

	Brain *getBrain() const;

	virtual void makeSound() const;
};

#endif
