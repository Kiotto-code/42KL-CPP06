#ifndef A_HPP
# define A_HPP

#include "Base.hpp"

class A : public Base
{
	private:
		static const std::string type;

	public:
		void whoAmI(void) const;
};

// class A : public Base
// {
// 	private:
// 		static const std::string type = "A";

// 	public:
// 		void whoAmI(void) const;
// }


#endif