#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
/**
 * @brief Cat class
 *
 */
class Cat : public AAnimal
{
private:
	Brain *_brain;

public:
	Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	virtual ~Cat();

	virtual void makeSound() const;
};

#endif
