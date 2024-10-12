/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:04:38 by ecarlier          #+#    #+#             */
/*   Updated: 2024/10/12 18:19:57 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cmath>
#include <regex.h>
#include <limits.h>


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
	UNDEFINNED,
};

class ScalarConverter
{
	private:
		ScalarConverter(); //private so it can't be instanciate
		ScalarConverter(const ScalarConverter &copy);

		ScalarConverter &operator=(const ScalarConverter &copy);


		static bool		checkRegex(const std::string str, const std::string pattern);

		static bool	isNull(const std::string str);
		static void	convertChar(const std::string str);
		static void	convertInt(const std::string str);
		static void	convertDouble(const std::string str);
		static void	convertFloat(const std::string str);

		static void displayAll(char c, int i, float f, double d, std::string str);
		static void	displayC(char c, std::string str);
		static void	displayI(int i, std::string str);
		static void	displayF(float f, std::string str) ;
		static void	displayD(double d, std::string str);

	public:
		static e_type	getType(const std::string &str);
		static void	convert(std::string str);
		~ScalarConverter();
};

#endif // ScalarConverter_HPP
