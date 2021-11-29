#include <iostream>
#include <ios>
#include <iomanip>
#include "Contact.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void):_count(0)
{
	std::cout << "PhoneBook Constructor called" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook Destructor called" << std::endl;
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

bool	contain_only_digits(std::string str)
{
	for (size_t i = 0; i < str.size(); ++i)
	{
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}

void	print_good_width(std::string str)
{	
	if (str.length() > 10)
		std::cout << std::setw(9) << str.substr(0, 9) << "." << "|";
	else
		std::cout << std::setw(10) << str << "|";
}

bool	PhoneBook::display_contacts(void) const
{	
	std::string	str;
	bool		res;
	int			index;

	if (!this->_count)
	{
		std::cout << "Phonebook is empty, please add a contact before !" << std::endl;
		return (true);
	}
	std::cout << "|" << std::setw(10) << "id" << "|";
	std::cout << std::setw(10) << "first name" << "|";
	std::cout << std::setw(10) << "last name" << "|";
	std::cout << std::setw(10) << "nickname"  << "|" << std::endl;
	for (unsigned int i = 0; i < this->_count; ++i)
	{	
		std::cout << '|';
		std::cout << std::setw(10);
		std::cout << i << "|";
		print_good_width(_tab[i].get_first_name());
		print_good_width(_tab[i].get_last_name());
		print_good_width(_tab[i].get_nickname());
		std::cout << std::endl;
	}
	res = false;
	while (!res)
	{	
		std::cout << "Please enter id:" << std::endl;
		std::getline(std::cin, str);
		if (std::cin.fail())
			return (false);
		if (str.length() != 1 || !isdigit(str[0]) || (char)str[0] > (char)(_count + 48))
			std::cerr << "Bad input please enter a correct id between 0 and " << (_count - 1) << std::endl;
		else
		{	
			index = (int)(str[0] - 48);
			std::cout << "id            : " << index << std::endl;
			std::cout << "first name    : " << _tab[index].get_first_name() << std::endl;
			std::cout << "last name     : " << _tab[index].get_last_name() << std::endl;
			std::cout << "nickname      : " << _tab[index].get_nickname() << std::endl;
			std::cout << "phonenumber   : " << _tab[index].get_phone_number() << std::endl;
			std::cout << "darkset secret: " << _tab[index].get_darkest_secret() << std::endl;
			res = true;
		}
	}
	return (true);
	
}

bool	PhoneBook::_add_name(Contact* contact, std::string name, void (Contact::*set)(std::string))
{
	std::string str;

	std::cout << "Please enter a " << name << " (only letters, minimum 2)" << std::endl;
	std::getline(std::cin, str);
	if (std::cin.fail())
		return (false);
	else if (str.length() < 2 || !contain_only_letters(str))
	{
		std::cerr << "Error please enter a correct input" << std::endl;
		this->_add_name(contact, name, set);
	}
	else
		(contact->*set)(str);
	return (true);
}

bool	PhoneBook::_add_phonenumber(Contact* contact)
{
	std::string str;

	std::cout << "Please enter a phone number (10 digits)" << std::endl;
	std::getline(std::cin, str);
	if (std::cin.fail())
		return (false);
	else if (str.length() != 10 || !contain_only_digits(str))
	{
		std::cerr << "Error please enter a correct input" << std::endl;
		this->_add_phonenumber(contact);
	}
	else
		contact->set_phone_number(str);
	return (true);
}

bool	PhoneBook::_add_secret(Contact* contact)
{
	std::string str;

	std::cout << "Please enter your darkest secret (minimum 4 characters)" << std::endl;
	std::getline(std::cin, str);
	if (std::cin.fail())
		return (false);
	else if (str.length() < 4)
	{
		std::cerr << "Error please enter a correct input" << std::endl;
		this->_add_secret(contact);
	}
	else
		contact->set_darkest_secret(str);
	return (true);
}

bool	PhoneBook::add_contact(void)
{
	Contact*	contact;
	
	
	if (this->_count > 7)
		contact = &this->_tab[0];
	else
		contact = &this->_tab[this->_count];
	if (!this->_add_name(contact, "first name", &Contact::set_first_name))
		return(false);
	if (!this->_add_name(contact, "last name", &Contact::set_last_name))
		return(false);
	if (!this->_add_name(contact, "nickname", &Contact::set_nickname))
		return(false);
	if (!this->_add_phonenumber(contact))
		return (false);
	if (!this->_add_secret(contact))
		return (false);
	if (this->_count <= 7)
		++this->_count;
	return (true);
}
