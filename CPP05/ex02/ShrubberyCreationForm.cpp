#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form::Form("ShruberryCreationForm", 145, 137),_target(target) {
	std::cout << "Default ShrubberyCreationForm constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : Form::Form("ShruberryCreationForm", 145, 137), _target(src._target) {
	std::cout << "Copy ShrubberyCreationForm constructor called\n";
}

ShrubberyCreationForm const &	ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs) {
	if (this != &rhs)
		*this = ShrubberyCreationForm(rhs);
	return (*this);
}

void	ShrubberyCreationForm::execute_function(void) const {
	std::string filename(_target + "_shruberry");
	std::ofstream out(filename.c_str());
	if (out.fail())
	{
		std::cerr << "fail to open " + filename << std::endl;
		return;
	}
	else
	{
		std::string const &tree =
"   oxoxoo    ooxoo\n\
  ooxoxo oo  oxoxooo\n\
 oooo xxoxoo ooo ooox\n\
 oxo o oxoxo  xoxxoxo\n\
  oxo xooxoooo o ooo\n\
   ooo\\oo\\  /o/o\n\
	\\  \\/ /\n\
	 |   /\n\
	 |  |\n\
	 | D|\n\
	 |  |\n\
	 |  |\n\
  ______/____\\____\n";
		out << tree;
	}
}
