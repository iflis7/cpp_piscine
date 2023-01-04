#include "PhoneBook.cls.hpp"
#include "main.hpp"

int main(void)
{
	PhoneBook phoneBook;
	std::string userInput = "";

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
			break;
		else
			std::cout << COLOR_RED << "Invalid command!\n"
					  << COLOR_DEFAULT;
	}

	return (0);
}
