#include "../include/AAnimal.hpp"
#include "../include/Brain.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"

void testAnimal(void)
{
	const AAnimal *doggy;
	const AAnimal *kitty;
	std::cout << std::endl;

	/* Should Return An Error */
	// const AAnimal	*meta;
	// meta = new AAnimal();
	// std::cout << "Type of meta = " << meta->getType() << std::endl;
	// meta->makeSound(); // output: AAnimals make a generic sound.
	// delete			meta;

	doggy = new Dog();
	std::cout << std::endl;

	kitty = new Cat();
	std::cout << std::endl;

	std::cout << "Type of doggy = " << doggy->getType() << std::endl;
	std::cout << "Type of kitty = " << kitty->getType() << std::endl;
	std::cout << std::endl;

	doggy->makeSound(); // output: Dog says: Woof!
	kitty->makeSound(); // output: Cat says: Meow!
	std::cout << std::endl;

	delete doggy;
	std::cout << std::endl;

	delete kitty;
}

int main(void)
{
	testAnimal();
	return (0);
}
