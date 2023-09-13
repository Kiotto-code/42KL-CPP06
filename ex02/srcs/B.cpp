#include "B.hpp"

const std::string B::type = "B";

void	B::whoAmI(void) const
{
	std::cout << "I'm " << type << std::endl;
}