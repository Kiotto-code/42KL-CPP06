// #ifndef SCALARCONVERTER_HPP
// # define SCALARCONVERTER_HPP


#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

// // # pragma once non eed pragma once if include guards were writtem
# include <iostream>
# include <iomanip>
# include <sstream>


class ScalarConverter
{
	private:
		// double input;




		ScalarConverter( void );
		// ScalarConverter(  std::string const &);
		// ScalarConverter(T value);
		~ScalarConverter( void );
		// avoid public from using the specific class method
		// has to be static for class fuction to use without having its object
		static bool	specialString(std::string const &parameter);
		static bool	isNumStr(std::string &parameter);

		static void	displayAll( double );
	public:
		static void	convert(std::string const &parameter);
		// class InvalidException: public std::exception
		// {
		// 	public:
		// 		const char	*what(void) const _NOEXCEPT;
		// };

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

