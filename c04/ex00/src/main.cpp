#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"

void testAnimals(void)
{
	// const Animal *anim;
	const Animal *doggy;
	// const Animal *kitty;

	// anim = new Animal();
	doggy = new Dog();
	// kitty = new Cat();

	std::cout << std::endl;
	// std::cout << "Type of anim = " << anim->getType() << std::endl;
	std::cout << "Type of doggy = " << doggy->getType() << std::endl;
	// std::cout << "Type of kitty = " << kitty->getType() << std::endl;

	std::cout << std::endl;
	// anim->makeSound();	// output: Animals make a generic sound.
	doggy->makeSound(); // output: Dog says: Woof!
	// kitty->makeSound(); // output: Cat says: Meow!

	std::cout << std::endl;
	// delete anim;
	delete doggy;
	// delete kitty;
}

void testWrongAnimal(void)
{
	const Animal *wrongAnimal;
	// const Animal *wrongCat;

	wrongAnimal = new WrongAnimal();
	// wrongCat = new WrongCat();

	std::cout << "Type of wrongAnimal = " << wrongAnimal->getType() << std::endl;
	// std::cout << "Type of wrongCat = " << wrongCat->getType() << std::endl;

	wrongAnimal->makeSound(); // output: WrongAnimals make a generic sound.
	// wrongCat->makeSound();	 // output: WrongAnimals make a generic sound.

	delete wrongAnimal;
	// delete wrongCat;
}

int main(void)
{
	std::cout << std::endl;
	// testAnimals();
	// std::cout << std::endl;
	testWrongAnimal();

	return (0);
}
