#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/Brain.hpp"
// #include "../../doctest.hpp"

int animalTest()
{
	int nb = 10;

	Animal *animals[nb];

	for (int i = 0; i < nb; i++)
	{
		if (i >= (nb / 2))
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	Cat copy(*(Cat *)animals[0]);
	std::cout << std::endl;
	for (int i = 0; i < nb; i++)
	{
		std::cout << std::setw(30) << std::left << copy.getBrain()->getIdea(i);
		std::cout << std::setw(30) << std::left << ((Cat *)animals[0])->getBrain()->getIdea(i) << std::endl;
	}
	std::cout << std::endl;
	for (int i = 0; i < nb; i++)
	{
		delete animals[i];
	}
	return (0);
}

#include <iostream>
#include <string>

int copyTest()
{
	// Test if a copy is deep or shallow
	Dog d1("Max");
	Dog d2 = d1;
	int nb = 5;

	if (d1.getType() == d2.getType())
		std::cout << std::endl
				  << "The copy is shallow :(" << std::endl
				  << std::endl;
	else
		std::cout << std::endl
				  << "The copy is deep :)" << std::endl
				  << std::endl;

	// Creating and deleting an array of Animal objects
	Animal *animals[nb];
	for (int i = 0; i < nb; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog("Dog " + std::to_string(i));
		else
			animals[i] = new Cat("Cat " + std::to_string(i));
	}

	for (int i = 0; i < nb; i++)
	{
		std::cout << animals[i]->getType() << std::endl;
		delete animals[i];
	}

	return 0;
}

int main(void)
{
	// 	testAnimal();
	copyTest();
	// test_wrong_animals();
	return (0);
}