#include "RobotomyRequestForm.hpp"

RobotomyRequestForm ::RobotomyRequestForm (std::string target) : Form::Form("RobotomyRequestForm ", 72, 45),_target(target) {
	std::cout << "Default RobotomyRequestForm  constructor called\n";
}

RobotomyRequestForm ::RobotomyRequestForm (RobotomyRequestForm  const & src) : Form::Form("RobotomyRequestForm ", 72, 45), _target(src._target) {
	std::cout << "Copy RobotomyRequestForm  constructor called\n";
}

RobotomyRequestForm  const &	RobotomyRequestForm ::operator=(RobotomyRequestForm  const & rhs) {
	if (this != &rhs)
		*this = RobotomyRequestForm (rhs);
	return (*this);
}

void	RobotomyRequestForm ::execute_function(void) const {
	std::string esc = "\033[m";
	std::string robotomized;
	srand(time(NULL));

	std::cout << "\033[35m" << "* ZIJDZIJDZIDRILLINGNOISZEESSS *" << esc << std::endl;
	if (rand() % 2)
		robotomized = "\033[32m has been 50% robotomized";
	else
		robotomized = "\033[31m has not been 50% robotomized";
	std::cout << _target << robotomized << esc <<  std::endl;
}
