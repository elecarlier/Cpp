/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:04:38 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/24 19:19:36 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cmath>


enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	POS_INFF,
	POS_INF,
	NEG_INFF,
	NEG_INF,
	NANF,
	NAND,
	ERROR,
};

class ScalarConverter
{
	private:
		ScalarConverter(); //private so it can't be instanciate
		ScalarConverter(const ScalarConverter &copy);
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &copy);

		static int	getType(const std::string &str);

		static void	display(char c);
		static void	display(int i);
		static void	display(float f);
		static void	display(double d);

	public:

		static void	convert(std::string str);
};

std::ostream &operator<<(std::ostream &o, ScalarConverter const &i);

#endif // ScalarConverter_HPP
