#include "../include/Animal.hpp"
#include "../include/Brain.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"

void test_animals(void)
{
	const Animal *doggy;
	const Animal *kitty;
	std::cout << std::endl;

	// const Animal	*meta;
	// meta = new Animal();
	// std::cout << "Type of meta = " << meta->getType() << std::endl;
	// meta->makeSound(); // output: Animals make a generic sound.
	// delete			meta;

	doggy = new Dog();
	kitty = new Cat();
	std::cout << std::endl;

	std::cout << "Type of doggy = " << doggy->getType() << std::endl;
	std::cout << "Type of kitty = " << kitty->getType() << std::endl;
	kitty->makeSound(); // output: Cat says: Meow!
	doggy->makeSound(); // output: Dog says: Woof!
	std::cout << std::endl;

	delete doggy;
	delete kitty;
}

int main(void)
{
	test_animals();
	return (0);
}
