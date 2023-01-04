#ifndef PHONEBOOK_CLS_HPP
# define PHONEBOOK_CLS_HPP

# include "Contact.cls.hpp"
# include "main.hpp"

class PhoneBook
{
  public:
	PhoneBook(void);
	~PhoneBook(void);

	void prompt(void) const;
	void add(void);
	void search(void) const;
	// TODO just for testing, delete afterwards.
	// void add_contact(std::string firstName,
	// 					std::string lastName,
	// 					std::string nickName,
	// 					std::string phoneNumber,
	// 					std::string secret);

  private:
	Contact _contacts[8];
	int _index;
	int _count;
	void _show_contact(int index) const;
	void _check_index(void);
	void _set_userinput(std::string message, void (Contact::*f)(std::string));
	std::string _truncate(std::string input) const;
	static int const _WIDTH = 10;
};

#endif
