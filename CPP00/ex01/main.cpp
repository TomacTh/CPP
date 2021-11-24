#include "PhoneBook.class.hpp"

int main(void)
{	
	PhoneBook 	phonebook;
	std::string str;
	bool		res;

	while(true)
	{
		std::cout << "Please enter a valid command (ADD | SEARCH | EXIT)" << std::endl;
		std::getline(std::cin, str);
		if (std::cin.fail())
			return (1);
		if (!str.compare("ADD"))
		{
			res = phonebook.add_contact();
			if (!res && !std::cin.eof())
			{
				std::cerr << "Error" << std::endl;
				return (1);
			}
			else if (res)
				std::cout << "Contact added !" << std::endl;
		}
		else if (!str.compare("SEARCH"))
		{	
			res = phonebook.display_contacts();
			if (!res && !std::cin.eof())
			{
				std::cerr << "Error" << std::endl;
				return (1);
			}
		}
		else if (!str.compare("EXIT"))
			break ;
		else
			std::cerr << "Command not valid" << std::endl;
	}
	return (0);
}
