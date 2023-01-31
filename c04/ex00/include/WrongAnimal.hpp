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

// class WrongAnimal
// {
// //   protected:
// // 	std::string _type;

//   public:
// 	// Constructors
// 	WrongAnimal();
// 	WrongAnimal(const WrongAnimal &copy);
// 	WrongAnimal &operator=(const WrongAnimal &src);
// 	// Destructor
// 	~WrongAnimal();

// 	// Public Methods
// 	void makeSound(void) const;
// 	std::string getType() const;
// 	void setType(std::string type);
//     // std::string getType(void) const;
// };
