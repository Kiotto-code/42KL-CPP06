#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void )
{
	std::cout << "[ScalarConverter] default constructor was being called " << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	std::cout << "[ScalarConverter] copy constructor was being called " << std::endl;
	*this = src;
}

ScalarConverter::~ScalarConverter ( void )
{
	std::cout << "[ScalarConverter] destructor was being called " << std::endl;
}

ScalarConverter &ScalarConverter::operator = (ScalarConverter const &src)
{
	return (*this);
	(void)src;
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

bool	ScalarConverter::isNumStr(std::string& str) {
	if (isalpha(str[1]))
		return false;
	if (str.back() == 'f')
		str.pop_back();
    std::istringstream iss(str);
    double testValue;

    // Attempt to read a double from the string
    if (iss >> testValue) {
        // Check if there are no trailing characters after the double
        char remaining;
        if (iss >> remaining) {
            return false; // If there are remaining characters, it's not a valid double
        }
        return true; // Successfully read a double
    }
    return false; // Couldn't read a double from the string
}

void	ScalarConverter::displayAll(double val )
{
	int myInt = static_cast<int>(val);
    float myFloat = static_cast<float>(val);
    char myChar = static_cast<char>((val));

	if (val > std::numeric_limits<char>::max() || val < std::numeric_limits<char>::min())
		std::cout << "char: overflow" << std::endl;
	else if (std::isprint(myChar) && val >= 0)
		std::cout << "Converted char: " << "'" << myChar << "'" << std::endl;
	else
		std::cout << "Converted char: " << "non-displayable" << std::endl;

	if (val > std::numeric_limits<int>::max() || val < std::numeric_limits<int>::min())
		std::cout << "Converted int: overflow" << std::endl;
	else
		std::cout << "Converted int: " << myInt << std::endl;

	std::cout << std::setprecision(1) << std::fixed;

	if (val > std::numeric_limits<float>::max() || val < std::numeric_limits<float>::lowest())
		std::cout << "Converted float: overflow" << std::endl;
	else
		std::cout << "Converted float: " << myFloat << "f" << std::endl;
	// std::cout << "Converted float: " << myFloat << "f" << std::endl;


	if (val > std::numeric_limits<double>::max() || val < std::numeric_limits<double>::lowest())
		std::cout << "Converted double: overflow" << std::endl;
	else
		std::cout << "Converted double: " << val << std::endl;
}

void	ScalarConverter::convert(std::string const &input)
{
		if (input.empty())
		{
			std::cout << "the parameter is empty !" << std::endl;
			return ;
		}
		std::string modInput = input;
	try
	{
		if (specialString(modInput))
			;
		else if (!isdigit(input[0]) && input.size() == 1)
			displayAll(static_cast<double>(input[0]));
		else if (isNumStr(modInput))
			displayAll(std::stod(modInput));
		else	
			std::cout << "No integer entry received, pls retry";
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
	catch (const std::out_of_range& e) {
		std::cout
		<< "char: overflow" << '\n'
		<< "int: overflow" << '\n'
		<< "float: overflow" << '\n'
		<< "double: overflow" << std::endl;
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
