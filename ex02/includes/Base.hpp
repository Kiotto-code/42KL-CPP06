#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include "Color.hpp"

class Base
{
	public:
		virtual ~Base();
		virtual void whoAmI() const = 0;
};

#endif