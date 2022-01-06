#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include <stdlib.h>

class RobotomyRequestForm  : public Form {
	private:
		std::string	_target;
		virtual	void	execute_function(void) const;
	public:
		RobotomyRequestForm (std::string);
		RobotomyRequestForm (void);
		RobotomyRequestForm (RobotomyRequestForm  const &);
		virtual ~RobotomyRequestForm(){}
		RobotomyRequestForm  const &	operator=(RobotomyRequestForm  const &);
};

#endif
