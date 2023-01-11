#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

/**
 * @brief Cat class
 * 
 */
class Cat : public Animal
{
  public:
	Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	virtual ~Cat();

	virtual void makeSound() const;
};

#endif


