#include "PhoneBook.cls.hpp"
#include "main.hpp"

PhoneBook::PhoneBook(void)
{
	this->_index = -1;
	this->_count = 0;
}

PhoneBook::~PhoneBook(void)
{
}

void PhoneBook::prompt(void) const
{
	std::cout << "=============[ " << COLOR_MAGENTA << "My Awesome PhoneBook"
				<< COLOR_DEFAULT << " ]=============\n"
				<< COLOR_CYAN
				<< "👇 To interact with the program enter: 👇\n"
				<< "[" << COLOR_YELLOW << "ADD" << COLOR_DEFAULT << "] || "
				<< "[" << COLOR_YELLOW << "SEARCH" << COLOR_DEFAULT << "] || "
				<< "[" << COLOR_YELLOW << "EXIT" << COLOR_DEFAULT << "]" << std::endl;
}

void PhoneBook::_check_index(void)
{
	if (this->_index == 7)
		this->_index = 0;
	else
		this->_index++;
	if (this->_count < 8)
		this->_count++;
}

void PhoneBook::_set_userinput(std::string message,
								void (Contact::*f)(std::string))
{
	std::string userinput;
	while (true)
	{
		std::cout << "\nEnter " << message << ": " << COLOR_GREEN;
		std::getline(std::cin, userinput);
		std::cout << COLOR_DEFAULT;
		if (userinput.size() > 0)
			break ;
		std::cout << COLOR_RED << "Input can't be empty!\n"
					<< COLOR_DEFAULT;
	}
	(this->_contacts[this->_index].*f)(userinput);
}

void PhoneBook::add(void)
{
	this->_check_index();
	PhoneBook::_set_userinput("First name", &Contact::setFirstName);
	PhoneBook::_set_userinput("Last name", &Contact::setLastName);
	PhoneBook::_set_userinput("Nick name", &Contact::setNickName);
	PhoneBook::_set_userinput("Phone number", &Contact::setPhoneNumber);
	PhoneBook::_set_userinput("Darkest secret", &Contact::setDarkestSecret);
}

void PhoneBook::search(void) const
{
	std::string userinput;
	int index;

	std::cout.fill('=');
	std::cout.width(this->_WIDTH * 4 + 5);
	std::cout << "\n";
	std::cout.fill(' ');
	std::cout.width(this->_WIDTH);
	std::cout << "Index"
				<< "|";
	std::cout.width(this->_WIDTH);
	std::cout << "First Name"
				<< "|";
	std::cout.width(this->_WIDTH);
	std::cout << "Last Name"
				<< "|";
	std::cout.width(this->_WIDTH);
	std::cout << "Nick Name" << std::endl;
	std::cout.fill('=');
	std::cout.width(this->_WIDTH * 4 + 5);
	std::cout << "\n";
	std::cout.fill(' ');
	for (int i = 0; i < this->_count; i++)
	{
		std::cout << COLOR_YELLOW;
		std::cout.width(this->_WIDTH);
		std::cout << i + 1 << COLOR_DEFAULT << "|";
		std::cout.width(this->_WIDTH);
		std::cout << this->_truncate(this->_contacts[i].getFirstName()) << "|";
		std::cout.width(this->_WIDTH);
		std::cout << this->_truncate(this->_contacts[i].getLastName()) << "|";
		std::cout.width(this->_WIDTH);
		std::cout << this->_truncate(this->_contacts[i].getNickName()) << std::endl;
	}
	if (this->_count == 0)
		std::cout << COLOR_RED << "Phonebook is empty\n"
					<< COLOR_DEFAULT;
	else
	{
		std::cout << "\nSelect Index: ";
		std::cout << COLOR_GREEN;
		std::getline(std::cin, userinput);
		std::cout << COLOR_DEFAULT;
		index = atoi(userinput.c_str());
		if (index <= this->_count && index > 0)
			PhoneBook::_show_contact(index - 1);
		else
			std::cout << COLOR_RED << "Invalid Index!\n"
						<< COLOR_DEFAULT;
	}

	// void PhoneBook::add_contact(std::string firstName,
	// 							std::string lastName,
	// 							std::string nickName,
	// 							std::string phoneNumber,
	// 							std::string secret)
	// {
	// 	this->_check_index();
	// 	this->_contacts[this->_index].setContact(firstName,
	// 												lastName,
	// 												nickName,
	// 												phoneNumber,
	// 												secret);
	// }
}

// void PhoneBook::_display_contact(int index) const
// 	{
// if (index < 0 || index >= num_contacts)
// {
// 	std::cout << "Error: index out of range." << std::endl;
// 	return ;
// }

// 		std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
// 		std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
// 		std::cout << "Nickname: " << contacts[index].getNickName() << std::endl;
// 		std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
// 		std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
// 	}

void PhoneBook::_show_contact(int index) const
{
	std::cout << std::endl;
	std::cout << COLOR_CYAN << "First Name: " << COLOR_DEFAULT << this->_contacts[index].getFirstName() << std::endl;
	std::cout << COLOR_CYAN << "Last Name: " << COLOR_DEFAULT << this->_contacts[index].getLastName() << std::endl;
	std::cout << COLOR_CYAN << "Nickname: " << COLOR_DEFAULT << this->_contacts[index].getNickName() << std::endl;
	std::cout << COLOR_CYAN << "Phone Number: " << COLOR_DEFAULT << this->_contacts[index].getPhoneNumber() << std::endl;
	std::cout << COLOR_CYAN << "Darkest Secret: " << COLOR_DEFAULT << this->_contacts[index].getDarkestSecret() << std::endl;
	std::cout << std::endl;
}

std::string PhoneBook::_truncate(std::string str) const
{
	if (str.length() > 10)
		return (str.substr(0, this->_WIDTH - 1) + ".");
	return (str);
}
