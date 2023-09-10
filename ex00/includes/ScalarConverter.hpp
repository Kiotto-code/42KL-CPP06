// #ifndef SCALARCONVERTER_HPP
// # define SCALARCONVERTER_HPP


#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

// // # pragma once non eed pragma once if include guards were writtem
# include <iostream>
# include <iomanip>
# include <cctype>


class ScalarConverter
{
	private:
		double input;
		std::string const &inputStr;




		ScalarConverter( void );
		// ScalarConverter(  std::string const &);
		// ScalarConverter(T value);
		~ScalarConverter( void );
		// avoid public from using the specific class method
		// has to be static for class fuction to use without having its object
		static bool	filterString(std::string const &parameter);
		static void	displayAll( double );
		// static bool checkInput (std::string const &parameter);
		// template<typename T>
		// static void	convertor(T &parameter);
		// static void	convertor(double parameter);
	public:
		static void	convert(std::string const &parameter);
		// int toInt() const {
        // // Implement your custom conversion logic to int here
		// 	return static_cast<int>(input);
		// }

		// float toFloat() const {
		// 	// Implement your custom conversion logic to float here
		// 	return static_cast<float>(input);
		// }

		// char toChar() const {
		// 	// Implement your custom conversion logic to char here
		// 	return static_cast<char>(static_cast<int>(input));
		// }
		class InvalidException: public std::exception
		{
			public:
				const char	*what(void) const _NOEXCEPT;
		};

		class NaNException: public std::exception
		{
			public:
				const char	*what(void) const _NOEXCEPT;
		};

		class PositiveInfinityException: public std::exception
		{
			public:
				const char	*what(void) const _NOEXCEPT;
		};

		class NegativeInfinityException: public std::exception
		{
			public:
				const char	*what(void) const _NOEXCEPT;
		};

};

// void	filterString(std::string const &parameter);

#endif

