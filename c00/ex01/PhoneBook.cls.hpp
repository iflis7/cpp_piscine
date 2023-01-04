#ifndef PHONEBOOK_CLS_HPP
#define PHONEBOOK_CLS_HPP

#include "Contact.cls.hpp"
#include "main.hpp"

class PhoneBook
{
public:
	PhoneBook(void);
	~PhoneBook(void);

	void prompt(void) const;
	void add(void);
	void add_contact(std::string FirstName,
					 std::string LastName,
					 std::string NickName,
					 std::string PhoneNumber,
					 std::string Secret);
	void search(void) const;
	void free_contacts(void);

private:
	Contact _contacts[8];
	void _show_contact(int index) const;
	int _index;
	int _count;
	void _check_index(void);
	void _set_userinput(std::string message, void (Contact::*f)(std::string));
	std::string _truncate(std::string input) const;
	static int const _WIDTH = 10;
};

#endif
