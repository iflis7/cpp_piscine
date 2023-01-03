#ifndef PHONEBOOK_CLS_HPP
# define PHONEBOOK_CLS_HPP

# include "Contact.cls.hpp"
#include "main.hpp"

const int	MAX_CONTACTS = 8;

class PhoneBook
{
  public:
	PhoneBook(void);
	~PhoneBook(void);

	void    add(const Contact &contact);
	void    search(int index);
	void    print(int index);
	void    exitBook(void);

	private:
	// Contact contacts[MAX_CONTACTS];
	// int num_contacts;
};

#endif
