#include "Contact.cls.hpp"

Contact::Contact(void)
{
}

Contact::Contact(std::string &firstName,
					std::string &lastName,
					std::string &nickName,
					std::string &phoneNumber,
					std::string &darkestSecret)
	: firstName(firstName),
		lastName(lastName),
		nickName(nickName),
		phoneNumber(phoneNumber),
		darkestSecret(darkestSecret)
{
}

Contact::~Contact(void)
{
}

void Contact::setContact(std::string firstName,
							std::string lastName,
							std::string nickName,
							std::string phoneNumber,
							std::string darkestSecret)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickName = nickName;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
}

void Contact::setFirstName(std::string name)
{
	this->firstName = name;
}

std::string Contact::getFirstName(void) const
{
	return (this->firstName);
}

void Contact::setLastName(std::string name)
{
	this->lastName = name;
}

std::string Contact::getLastName(void) const
{
	return (this->lastName);
}

void Contact::setNickName(std::string name)
{
	this->nickName = name;
}

std::string Contact::getNickName(void) const
{
	return (this->nickName);
}

void Contact::setPhoneNumber(std::string number)
{
	this->phoneNumber = number;
}

std::string Contact::getPhoneNumber(void) const
{
	return (this->phoneNumber);
}

void Contact::setDarkestSecret(std::string secret)
{
	this->darkestSecret = secret;
}

std::string Contact::getDarkestSecret(void) const
{
	return (this->darkestSecret);
}
