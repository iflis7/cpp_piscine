#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/Brain.hpp"
// #include "../../doctest.hpp"

int main()
{

	Animal *animals[10];

	for (int i = 0; i < 10; i++)
	{
		if (i >= 5)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	Cat copy(*(Cat *)animals[0]);
	std::cout << std::endl;
	for (int i = 0; i < 100; i++)
	{
		std::cout << std::setw(30) << std::left << copy.getBrain()->getIdea(i);
		std::cout << std::setw(30) << std::left << ((Cat *)animals[0])->getBrain()->getIdea(i) << std::endl;
	}
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
	{
		delete animals[i];
	}
}

<<<<<<< HEAD
// TEST_CASE("Test case 1") {
//     CHECK(1 + 1 == 2);
//     CHECK(2 * 2 == 4);
// }

// TEST_CASE("Test case 2") {
//     CHECK(3 - 1 == 2);
//     CHECK(4 / 2 == 2);
// }

// int main(int argc, const char *const *argv){
// 	doctest::Context ctx;
// ctx.setOption("abort-after", 5);  // default - stop after 5 failed asserts
// ctx.applyCommandLine(argc, argv); // apply command line - argc / argv
// ctx.setOption("no-breaks", true); // override - don't break in the debugger
// int res = ctx.run();              // run test cases unless with --no-run
// if(ctx.shouldExit())              // query flags (and --exit) rely on this
//     return res;                   // propagate the result of the tests
// // your actual program execution goes here - only if we haven't exited
// return res; // + your_prog
// 	doctest::Context ctx;
// 	ctx.applyCommandLine(argc, argv);
// 	int res = ctx.run();
// 	if (ctx.shouldExit())
// 	{
// 		return res;
// 	}
// }
=======
// void	test_wrong_animals(void)
// {
// 	const Animal	*wrong_meta;
// 	const Animal	*wrong_i;

// 	wrong_meta = new WrongAnimal();
// 	wrong_i = new WrongCat();
// 	std::cout << "Type of wrong_meta = " << wrong_meta->getType() << std::endl;
// 	std::cout << "Type of wrong_i = " << wrong_i->getType() << std::endl;
// 	wrong_i->makeSound();    // output: WrongAnimals make a generic sound.
// 	wrong_meta->makeSound(); // output: WrongAnimals make a generic sound.
// 	delete			wrong_meta;
// 	delete			wrong_i;
// }

int	main(void)
{
	test_animals();
	// test_wrong_animals();
	return (0);
}
>>>>>>> ad1befb088b1786556af918d454ee3a8ca9d1dfc
