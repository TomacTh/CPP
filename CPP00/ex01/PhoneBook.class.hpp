#include "Contact.class.hpp"

class	PhoneBook 
{
public:
	PhoneBook(void);
	~PhoneBook(void);
	unsigned int	get_count(void);
	bool			add_contact(void);
	bool			display_contacts(void);

private:
	bool			add_name(Contact *contact, std::string name, void (Contact::*f)(std::string));
	bool			add_phonenumber(Contact *contact);
	bool			add_secret(Contact *contact);
	void			display_contact(unsigned int i);
	unsigned int	count;
	Contact			tab[8];
};
