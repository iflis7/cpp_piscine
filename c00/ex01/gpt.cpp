#include "PhoneBook.cls.hpp"
#include <iomanip>
#include <iostream>
#include <string>

const int	MAX_CONTACTS = 8;

class Contact
{
  private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

  public:
	Contact(const std::string &first_name, const std::string &last_name,
			const std::string &nickname, const std::string &phone_number,
			const std::string &darkest_secret)
		: first_name(first_name), last_name(last_name), nickname(nickname),
			phone_number(phone_number),
			darkest_secret(darkest_secret)
	{
	}

	std::string get_first_name() const
	{
		return (first_name);
	}
	std::string get_last_name() const
	{
		return (last_name);
	}
	std::string get_nickname() const
	{
		return (nickname);
	}
	std::string get_phone_number() const
	{
		return (phone_number);
	}
	std::string get_darkest_secret() const
	{
		return (darkest_secret);
	}
};

class PhoneBook
{
  private:
	Contact contacts[MAX_CONTACTS];
	int num_contacts;

  public:
	PhoneBook()
		: num_contacts(0)
	{
	}

	void add_contact(const Contact &contact)
	{
		if (num_contacts == MAX_CONTACTS)
		{
			for (int i = 0; i < MAX_CONTACTS - 1; i++)
			{
				contacts[i] = contacts[i + 1];
			}
			contacts[MAX_CONTACTS - 1] = contact;
		}
		else
		{
			contacts[num_contacts] = contact;
			num_contacts++;
		}
	}

	void display_contacts() const
	{
		std::cout << "Index | First Name | Last Name | Nickname" << std::endl;
		for (int i = 0; i < num_contacts; i++)
		{
			std::string first_name = contacts[i].get_first_name();
			std::string last_name = contacts[i].get_last_name();
			std::string nickname = contacts[i].get_nickname();

			if (first_name.size() > 10)
			{
				first_name = first_name.substr(0, 7) + "...";
			}
			if (last_name.size() > 10)
			{
				last_name = last_name.substr(0, 7) + "...";
			}
			if (nickname.size() > 10)
			{
				nickname = nickname.substr(0, 7) + "...";
			}

			std::cout << std::right << std::setw(5) << i << " | " << std::setw(10) << first_name << " | "
						<< std::setw(10) << last_name << " | " << std::setw(10) << nickname << std::endl;
		}
	}

	void display_contact(int index) const
	{
		if (index < 0 || index >= num_contacts)
		{
			std::cout << "Error: index out of range." << std::endl;
			return ;
		}

		std::cout << "First Name: " << contacts[index].get_first_name() << std::endl;
		std::cout << "Last Name: " << contacts[index].get_last_name() << std::endl;
		std::cout << "Nickname: " << contacts[index].get_nickname() << std::endl;
		std::cout << "Phone Number: " << contacts[index].get_phone_number() << std::endl;
		std::cout << "Darkest Secret: " << contacts[index].get_darkest_secret() << std::endl;
	}