#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <ctime>

Base	*generate(void)
{
	srand(time(0));
	Base				*arr[] = {
		new A(),
		new B(),
		new C(),
	};
	const unsigned int	size = (sizeof(arr) / sizeof(arr[0]));
	const unsigned int	ret = rand() % size;

	std::cout << ret << std::endl;
	for (unsigned int i = 0; i < size; i++)
	{
		if (i != ret)
			delete arr[i];
	}
	return (arr[ret]);
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "A" << std::endl;
	if (dynamic_cast<B *>(p) != NULL)
		std::cout << "B" << std::endl;
	if (dynamic_cast<C *>(p) != NULL)
		std::cout << "C" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		A&	a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl; 
	}
	catch(const std::exception& e) {}
	try
	{
		B&	b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl; 
	}
	catch(const std::exception& e) {}
	try
	{
		C&	c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl; 
	}
	catch(const std::exception& e) {}
}

int main()
{
	{
		A test;
		test.whoAmI();
		identify(test);
		identify(&test);
	}
	{
		B test;
		test.whoAmI();
	}
	{
		C test;
		test.whoAmI();
	}
	{
		
		Base *test = generate();
		test->whoAmI();
		identify(test);
		identify(*test);
	}
}
