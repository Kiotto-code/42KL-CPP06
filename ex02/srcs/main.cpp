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

int main()
{
	{
		A test;
		test.whoAmI();
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
	}
}