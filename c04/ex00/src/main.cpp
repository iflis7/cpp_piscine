#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"

void test_animals(void)
{
	const Animal *meta;
	const Animal *doggy;
	const Animal *kitty;

	meta = new Animal();
	doggy = new Dog();
	kitty = new Cat();
	std::cout << "Type of meta = " << meta->getType() << std::endl;
	std::cout << "Type of doggy = " << doggy->getType() << std::endl;
	std::cout << "Type of kitty = " << kitty->getType() << std::endl;
	kitty->makeSound(); // output: Cat says: Meow!
	doggy->makeSound(); // output: Dog says: Woof!
	meta->makeSound();	// output: Animals make a generic sound.

	delete meta;
	delete doggy;
	delete kitty;
}

void test_wrong_animals(void)
{
	const Animal *wrong_meta;
	const Animal *wrong_i;

	wrong_meta = new WrongAnimal();
	wrong_i = new WrongCat();
	std::cout << "Type of wrong_meta = " << wrong_meta->getType() << std::endl;
	std::cout << "Type of wrong_i = " << wrong_i->getType() << std::endl;
	wrong_i->makeSound();	 // output: WrongAnimals make a generic sound.
	wrong_meta->makeSound(); // output: WrongAnimals make a generic sound.
	delete wrong_meta;
	delete wrong_i;
}

int main(void)
{
	test_animals();
	std::cout << std::endl;
	test_wrong_animals();

	return (0);
}
