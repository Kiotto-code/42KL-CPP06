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
		ScalarConverter( void );
		ScalarConverter(ScalarConverter const &src);
		~ScalarConverter( void );
		static bool	specialString(std::string const &parameter);
		static bool	isNumStr(std::string &parameter);

		static void	displayAll( double );
	public:
		ScalarConverter	&operator = (ScalarConverter const &src);
		static void	convert(std::string const &parameter);

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

#endif

