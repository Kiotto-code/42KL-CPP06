# include "ScalarConverter.hpp"

int main(void)
{
	std::string num = "48";
	ScalarConverter::convert(num);
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