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

ScalarConverter::~ScalarConverter ( void )
{
	std::cout << "[ScalarConverter] destructor was being called " << std::endl;
}


bool	ScalarConverter::specialString(std::string const &str)
{
	if (str == "nan" || str == "nanf")
		throw (NaNException());
	else if (str == "+inf" || str == "+inff")
		throw (PositiveInfinityException());
	else if (str == "-inf" || str == "-inff")
		throw (NegativeInfinityException());
	else
		return (false);
	return (true);
}

bool	ScalarConverter::isNumStr(std::string &str)
{
	if (str.back() == 'f')
		str.pop_back();
	for (std::string::size_type i=0; i<str.size(); i++)
	{
		if (isdigit(str[i]) || str[i] == '.')
			i++;
		else if (!isdigit(str[i]))
			return false;
	}
	return (true);
}

void	ScalarConverter::displayAll( double val )
{
	int myInt = static_cast<int>(val);
    float myFloat = static_cast<float>(val);
    char myChar = static_cast<char>(static_cast<int>(val));
    // char myChar = static_cast<char>((val));

	std::cout << "Converted int: " << myInt << std::endl;
	std::cout << std::setprecision(1) << std::fixed;
	std::cout << "Converted double: " << val << std::endl;
    std::cout << "Converted float: " << myFloat << "f" << std::endl;
	if (isprint(myChar))
		std::cout << "Converted char: " << myChar << std::endl;
	else
		std::cout << "Converted char: " << "Not Printable" << std::endl;

}

void	ScalarConverter::convert(std::string const &input)
{
	if (input.empty())
	{
		std::cout << "the parameter is empty !" << std::endl;
		return ;
	}
	std::string modInput;
	for (std::string::size_type i = 0; i < input.size(); ++i) {
        if (input[i] != ' ' && input[i] != '\t') { // Check if the character is not a space or tab
            modInput += input[i]; // Append non-space and non-tab characters to the result
        }
    }

	try
	{
		if (specialString(modInput))
			;
		else if (isalpha(modInput[0]) && modInput.size() == 1)
			displayAll(static_cast<double>(modInput[0]));
		else if (isNumStr(modInput))
			displayAll(std::stod(modInput));
		else	
			std::cout << "No integer entry receiveed, pls retry";
	}
	
	catch (const PositiveInfinityException &e)
	{
		std::cout
			<< "char: impossible" << '\n'
			<< "int: impossible" << '\n'
			<< "float: +inff" << '\n'
			<< "double: +inf" << std::endl;
	}
	catch (const NegativeInfinityException &e)
	{
		std::cout
			<< "char: impossible" << '\n'
			<< "int: impossible" << '\n'
			<< "float: -inff" << '\n'
			<< "double: -inf" << std::endl;
	}
	catch (const NaNException &e)
	{
		std::cout
			<< "char: impossible" << '\n'
			<< "int: impossible" << '\n'
			<< "float: nanf" << '\n'
			<< "double: nan" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << ": " << modInput << std::endl;
	}

}

/* Exception */
const char	*ScalarConverter::NaNException::what(void) const _NOEXCEPT
{
	return ("ScalarConverter: NaN");
}

const char	*ScalarConverter::PositiveInfinityException::what(void) const _NOEXCEPT
{
	return ("ScalarConverter: PositiveInfinity");
}

const char	*ScalarConverter::NegativeInfinityException::what(void) const _NOEXCEPT
{
	return ("ScalarConverter: NegativeInfinity");
}
