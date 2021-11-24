#pragma once
#include "Contact.hpp"

class	PhoneBook 
{
public:
	PhoneBook(void);
	~PhoneBook(void);
	bool			add_contact(void);
	bool			display_contacts(void) const;

private:
	bool			_add_name(Contact *contact, std::string name, void (Contact::*f)(std::string));
	bool			_add_phonenumber(Contact *contact);
	bool			_add_secret(Contact *contact);
	unsigned int	_count;
	Contact			_tab[8];
};
