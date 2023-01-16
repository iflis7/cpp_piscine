#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/Brain.hpp"

void	test_animals(void)
{
	const Animal	*meta;
	const Animal	*j;
	const Animal	*i;

	meta = new Animal();
	j = new Dog();
	i = new Cat();
	std::cout << "Type of meta = " << meta->getType() << std::endl;
	std::cout << "Type of j = " << j->getType() << std::endl;
	std::cout << "Type of i = " << i->getType() << std::endl;
	i->makeSound();    // output: Cat says: Meow!
	j->makeSound();    // output: Dog says: Woof!
	meta->makeSound(); // output: Animals make a generic sound.
	delete			meta;
	delete			j;
	delete			i;
}

void	test_wrong_animals(void)
{
	const Animal	*wrong_meta;
	const Animal	*wrong_i;

	wrong_meta = new WrongAnimal();
	wrong_i = new WrongCat();
	std::cout << "Type of wrong_meta = " << wrong_meta->getType() << std::endl;
	std::cout << "Type of wrong_i = " << wrong_i->getType() << std::endl;
	wrong_i->makeSound();    // output: WrongAnimals make a generic sound.
	wrong_meta->makeSound(); // output: WrongAnimals make a generic sound.
	delete			wrong_meta;
	delete			wrong_i;
}

int	main(void)
{
	test_animals();
	test_wrong_animals();
	return (0);
}
