//#include "PhoneBook.class.hpp"
//#include "Contact.class.hpp"
#include <iostream>


class	Contact
{
public:
	Contact(void);
	~Contact(void);
	//std::string		get_first_name(void);
	//std::string		get_last_name(void);
	//std::string		get_nick_name(void);
	void	set_first_name(std::string);
	void	set_last_name(std::string);
	void	set_nickname(std::string);
	//std::string		set_phone_number(void);
	//std::string		set_darkest_secret(void);

private:
	std::string		first_name;
	std::string		last_name;
	std::string		nick_name;
	std::string		phone_number;
	std::string		darkest_secret;
};

class	PhoneBook 
{
public:
	PhoneBook(void);
	~PhoneBook(void);
	unsigned int	get_count(void);
	bool			add_contact(void);

private:
	bool			add_name(Contact *contact, std::string name, void (Contact::*f)(std::string));
	bool			add_phonenumber(Contact *contact);
	unsigned int	count;
	Contact			tab[8];
};

Contact::Contact(void)
{
	std::cout << "Contact Constructor called\n";
}

Contact::~Contact(void)
{
	std::cout << "Contact Destructor called\n";
}


void	Contact::set_nickname(std::string str)
{
	this->nick_name = str;
}

PhoneBook::PhoneBook(void):count(0)
{
	std::cout << "PhoneBook Constructor called\n";
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook Destructor called\n";
}

bool	contain_only_letters(std::string str)
{
	for (size_t i = 0; i < str.size(); ++i)
	{
		if (!isalpha(str[i]))
			return (false);
	}
	return (true);
}

bool	PhoneBook::add_name(Contact *contact, std::string name, void (Contact::*set)(std::string))
{
	std::string str;

	std::cout << "Please enter a " << name << " (mininum two letters)\n";
	if (std::getline(std::cin, str) != std::cin)
		return (false);
	else if (str.length() < 2 || !contain_only_letters(str))
	{
		std::cerr << "Error please enter a correct input\n";
		this->add_name(contact, name, set);
	}
	else
		(contact->*set)(str);
	return (true);
}

bool	PhoneBook::add_contact(void)
{	
	Contact *contact;
	
	
	if (this->count >= 7)
		contact = &this->tab[0];
	else
		contact = &this->tab[this->count];
	
	//std::string		first_name;
	//std::string		last_name;
	//std::string		nick_name;
	//std::string		phone_number;
	//std::string		darkest_secret;

	//void (Contact::*set)(std::string) = ;
	if (!this->add_name(contact, "first name", &Contact::set_first_name))
		//return(false);
	//if (!add_name(contact, "last name", &Contact::set_last_name))
		//return(false);
	//if (!add_name(contact, "nickname", &Contact::set_nickname))
		//return(false);
	if (this->count >= 7)
		++this->count;
	return (true);	

}

unsigned int	PhoneBook::get_count(void)
{
	return (this->count);
}

int main(void)
{
	PhoneBook pb;
	pb.add_contact();
	//bool			add_name(Contact *contact, std::string name, void (Contact::*f)(std::string))
}

