#pragma once
#include <iostream>

class Karen
{
public:
	Karen(void);
	~Karen(void);
	void complain(std::string) const;
private:
	void debug(void) const;
	void info(void) const;
	void warning(void) const;
	void error(void) const;
};
