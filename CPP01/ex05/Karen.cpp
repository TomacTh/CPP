#include "Karen.hpp"

Karen::Karen(void)
{
	std::cout << "Karen constructor called" << std::endl;
}

Karen::~Karen(void)
{
	std::cout << "Karen destructor called" << std::endl;
}

void	Karen::debug(void) const
{
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void	Karen::info(void) const
{
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void	Karen::warning(void) const
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month" << std::endl;
}

void	Karen::error(void) const
{
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void	Karen::complain(std::string level) const
{
	void (Karen::*tab_f[4])(void) const = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error};
	const std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int i = 0;
	while (i < 4)
	{	
		if (!level.compare(levels[i]))
			break ;
		++i;
	}
	if (i < 4)
		(this->*tab_f[i])();
}
