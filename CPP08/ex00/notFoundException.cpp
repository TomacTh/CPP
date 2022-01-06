#include "easyfind.hpp"

NotFoundException::~NotFoundException(void) throw() {}
NotFoundException::NotFoundException(void) throw() {}
const char	*NotFoundException::what(void) const throw() { return "Not found\n";}


