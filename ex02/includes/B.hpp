#ifndef B_HPP
# define B_HPP

#include "Base.hpp"

class B : public Base
{
	private:
		static const std::string type;

	public:
		void whoAmI(void) const;
};

#endif