#include "A.hpp"

const std::string A::type = "A";

void	A::whoAmI(void) const
{
	std::cout << "I'm " << type << std::endl;
}