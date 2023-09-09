// // # include "includes/ScalarConverter.hpp"
// # include "ScalarConverter.hpp"

#include "ScalarConverter.hpp"
#include <iomanip>
#include <cctype>
#include <iostream>

ScalarConverter::ScalarConverter( void )
{
	std::cout << "[ScalarConverter] default constructor was being called " << std::endl;
}

// ScalarConverter::ScalarConverter( std::string const &parameter ) : inputStr ( parameter )
// {
// 	std::cout << "[ScalarConverter] input constructor was being called " << std::endl;
// };

ScalarConverter::~ScalarConverter ( void )
{
	std::cout << "[ScalarConverter] destructor was being called " << std::endl;
}


bool	ScalarConverter::filterString(std::string const &parameter)
{
	
}

void	ScalarConverter::displayAll( double val )
{
	ScalarConverter converter( val );
	int myInt = converter.toInt();
    float myFloat = converter.toFloat();
    char myChar = converter.toChar();

	std::cout << "Converted int: " << myInt << std::endl;
    std::cout << "Converted float: " << myFloat << std::endl;
    std::cout << "Converted char: " << myChar << std::endl;
}

// void	ScalarConverter::convertor(double parameter) : input(parameter)
// {
// 	double myDouble = 0;
// 	if (typeid(parameter) == typeid(char))
// 		myDouble = parameter

// }

void	ScalarConverter::convert(std::string const &parameter)
{
	if (parameter.empty())
	{
		std::cout << "the parameter is empty !" << std::endl;
		return ;
	}
	setconverter(parameter);
	// else if (parameter.size() > 1)
	// 	filterString(parameter);
	if (isalpha(parameter[0]) && parameter.size() == 1)
	{
		// ScalarConverter converter( static_cast<double>(parameter[0]) );
		displayAll(static_cast<double>(parameter[0]));
	}
	else if (checkInput(parameter))
	{
		// ScalarConverter converter( std::stod(parameter));
		displayAll(std::stod(parameter));
	}
	else	
		std::cout << "No integer entry receiveed, pls retry";
		// convertor(<int> std::stod (parameter));

}







