#include "PhoneBook.cls.hpp"
#include "main.hpp"

// static void	popuplate_phonebook(PhoneBook *book)
// {
// 	book->add_contact("Rene", "Kaufmann", "Kromolux", "555-012345789", "C/C++ Coder");
// 	book->add_contact("Rudi Roger", "The Rabbit Man", "RRRRRRRRRRRRRR", "555-Rabbit", "loves to eat carrots");
// 	book->add_contact("Arnold", "Schwarzenegger", "Arni", "555-California", "Mr. Universe");
// 	book->add_contact("Elon", "Musk", "Muski", "555-America", "Tesla founder");
// 	book->add_contact("Jesus", "Christus", "JC", "555-Heaven", "Gods son");
// 	book->add_contact("Tom", "Harly", "TH", "555-South_west", "Fascion desginer");
// 	book->add_contact("One", "Harly", "TH", "555-South_west", "Fascion desginer");
// 	book->add_contact("Last", "Harly", "TH", "555-South_west", "Fascion desginer");
// }

int	main(void)
{
	PhoneBook	phoneBook;
	std::string	userInput = "";

	// popuplate_phonebook(&phoneBook);
	while (true)
	{
		phoneBook.prompt();
		std::cout << COLOR_GREEN;
		std::getline(std::cin, userInput);
		std::cout << COLOR_DEFAULT;
		if (!userInput.compare("ADD"))
			phoneBook.add();
		else if (!userInput.compare("SEARCH"))
			phoneBook.search();
		else if (!userInput.compare("EXIT"))
			break ;
		else
			std::cout << COLOR_RED << "Invalid command!\n" << COLOR_DEFAULT;
	}
	return (0);
}

