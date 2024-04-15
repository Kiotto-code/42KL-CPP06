#include "C.hpp"

const std::string C::type = "C";

void	C::whoAmI(void) const
{
	std::cout << "I'm " << type << std::endl;
}