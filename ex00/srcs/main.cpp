# include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	ScalarConverter asd;

	if (ac == 2)	
		// ScalarConverter::convert(av[1]);
		asd.convert(av[1]);
	else
		std::cout << "Wrong argument entered!" << std::endl;
}


// int main() {
//     double myDouble = 49.1;
//     CustomConverter converter(myDouble);

//     int myInt = converter.toInt();
//     float myFloat = converter.toFloat();
//     char myChar = converter.toChar();

//     std::cout << "Converted int: " << myInt << std::endl;
//     std::cout << "Converted float: " << myFloat << std::endl;
//     std::cout << "Converted char: " << myChar << std::endl;

//     return 0;
// }