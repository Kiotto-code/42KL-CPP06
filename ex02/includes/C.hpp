#ifndef C_HPP
# define C_HPP

#include "Base.hpp"

class C : public Base
{
	private:
		static const std::string type;

	public:
		void whoAmI(void) const;
};

#endif