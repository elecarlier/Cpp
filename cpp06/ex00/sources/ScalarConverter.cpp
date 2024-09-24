/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:06:15 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/24 20:05:40 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	//std::cout << "\033[33m" << "Default constructor called" << "\033[0m" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	//std::cout << "\033[32m" << "Destructor called" << "\033[0m" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	//std::cout << "\033[34m" << "Copy constructor called" << "\033[0m" << std::endl;
	*this = copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	//::cout << "\033[35m" << "Copy assignment operator called" << "\033[0m" << std::endl;
	if (this != &copy)
		*this = copy;
	return *this;
}


void	ScalarConverter::convert(std::string str )
{

	char	char_value;
	int		int_value;
	float	float_value;
	double	double_value;

	switch(getType(str))
	{
		case CHAR:
		{
			// char_value = str[0];
			// int_value = static_cast<int>(char_value);
			// float_value = static_cast<float>(char_value);
			// double_value = static_cast<double>(char_value);
			//display + convert
			break;
		}

		case INT:
		{

		}
		case FLOAT:
		case POS_INFF:
		case NEG_INFF:
		case NANF:
		{
			break;
		}
		case DOUBLE:
		case POS_INF:
		case NEG_INF:
		case NAND:
		{

			break;
		}
		case ERROR:
	}
}

int	ScalarConverter::getType(const std::string &str)
{

	// if (str.empty())
	// 	return ERROR;
	if (str.length() == 1 && str.at(0) >= 0 && str.at(0) >= 127 && !isdigit(str.at(0)))
		return CHAR;

	

	// if (str == "-inff")
	// 	return NEG_INFF;
	// else if (str == "+inff")
	// 	return POS_INFF;
	// else if (str == "+inf")
	// 	return POS_INF;
	// else if (str == "-inf")
	// 	return NEG_INF;
}
// void	ScalarConverter::display(char c)
// {
// 	std::cout << "char : ";

// 	if (c < 32 || c > 126)
// 		std::cout << "Non displayable" << std::endl;
// 	else
// 		std::cout << "'" << c << "'" << std::endl;
// }
