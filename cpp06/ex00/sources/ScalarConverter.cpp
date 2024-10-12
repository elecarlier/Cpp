/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:06:15 by ecarlier          #+#    #+#             */
/*   Updated: 2024/10/12 19:46:28 by ecarlier         ###   ########.fr       */
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
	switch(getType(str))
	{
		case CHAR:
		{
			convertChar(str);
			break;
		}
		case INT:
		{
			convertInt(str);
			break;
		}
		case FLOAT:
		{
			convertFloat(str);
			break;
		}
		case DOUBLE:
		{
			convertDouble(str);
			break;
		}
		case POS_INFF:
		case POS_INF:
		{
			std::cout << "char: impossible"<< std::endl;
			std::cout << "int: impossible"<< std::endl;
			std::cout << "float: +inff"<< std::endl;
			std::cout << "double: +inf"<< std::endl;
			break;
		}
		case NEG_INFF:
		case NEG_INF:
		{
			std::cout << "char: impossible"<< std::endl;
			std::cout << "int: impossible"<< std::endl;
			std::cout << "float: -inff"<< std::endl;
			std::cout << "double: -inf"<< std::endl;
			break;
		}
		case NANF:
		case NAND:
		{
			std::cout << "char: impossible"<< std::endl;
			std::cout << "int: impossible"<< std::endl;
			std::cout << "float: nanf"<< std::endl;
			std::cout << "double: nan"<< std::endl;
			break;
		}
		case UNDEFINNED:
		{
			std::cout << "char: impossible"<< std::endl;
			std::cout << "int: impossible"<< std::endl;
			std::cout << "float: impossible"<< std::endl;
			std::cout << "double: impossible"<< std::endl;
			break;
		}
		case ERROR:
			std::cout << "Error: impossible to identidy type" << std::endl;
			break;
	}
}

/*
regcomp : compile regex, prend la chaine de caracteres du motif et la transforme en une expression reguliere
regexec : execute la recherche, renvoie 0 si la correspondance est trouvee, on utilise == 0
donc si une correspondance est trouve -> 0 == 0 -> true
*/
bool ScalarConverter::checkRegex(const std::string str, const std::string pattern)
{
	regex_t regex;
	if (regcomp(&regex, pattern.c_str(), REG_EXTENDED) != 0)
	{
		std::cout << "Regex failed" << std::endl;
		return (false);
	}
	bool match = regexec(&regex, str.c_str(), 0, NULL, 0) == 0;
	regfree(&regex);
	return (match);
}


/*
^[[:space:]]*[+-]?[0-9]+$ ->
^[...] motif commence au debut de la chaine
[:space:]* 0 ou plusieurs espaces
[+-]? facultatif
[0-9]+ (+ signifie au moins un chiffre)
$ rien a la fin de la chaine

*/
e_type	ScalarConverter::getType(const std::string &str)
{

	e_type res = UNDEFINNED;
	if (str.empty())
		res = ERROR;
	else if (checkRegex(str, "^.$") && !isdigit(str[0]))
		res = CHAR;
	else if (str == "-inff")
		res = NEG_INFF;
	else if (str == "+inff")
		res =  POS_INFF;
	else if (str == "+inf")
		res = POS_INF;
	else if (str == "-inf")
		res = NEG_INF;
	else if (str == "nan")
		res = NAND;
	else if  (str == "nanf")
		res = NANF;
	else if (checkRegex(str, "^[[:space:]]*[+-]?[0-9]+$"))
		res = INT;
	else if (checkRegex(str, "^[[:space:]]*[+-]?[0-9]+\\.[0-9]+f$"))
		res = FLOAT;
	else if (checkRegex(str, "^[[:space:]]*[+-]?[0-9]+\\.[0-9]+$"))
		res = DOUBLE;

	return (res);
}

/*------------------------------- Conversion -------------------------------*/

void	ScalarConverter::convertChar(const std::string str)
{
	char	c = static_cast<char>(str[0]);
	int		i = static_cast<int>(c);
	float	f = static_cast<float>(c);
	double	d = static_cast<double>(c);
	displayAll(c, i, f, d, str);
}

void	ScalarConverter::convertInt(const std::string str)
{
	int			i = atoi(str.c_str());
	long long	l = atoll(str.c_str());
	double d = strtod(str.c_str(), NULL);

	if (l > static_cast<long long>(INT_MAX) || l < static_cast<long long>(INT_MIN))
		displayAll(0, 0, 0, 0, str); //conversion not possible without losing precision
	else if (d < static_cast<double>(INT_MIN) || d > static_cast<double>(2147483647) || d != static_cast<int>(d))
	{
		displayAll(0, 0, 0, 0, str);
	}
	else
	{
		char		c = static_cast<char>(i);
		float		f = static_cast<float>(i);
		double		d = static_cast<double>(i);
		displayAll(c, i, f, d, str);
	}
}

void	ScalarConverter::convertDouble(const std::string str)
{
	double		d = strtod(str.c_str(), NULL);
	if (d < static_cast<double>(INT_MIN) || d > static_cast<double>(INT_MAX))
	{
		displayAll(0, 0, 0, 0, str);  // Not possible to convert to int
	}
	else
	{
		float		f = static_cast<float>(d);
		int			i = static_cast<int>(d);
		char		c = static_cast<char>(d);
		displayAll(c, i, f, d, str);
	}

}


void	ScalarConverter::convertFloat(const std::string str)
{
	float		f = strtof(str.c_str(), NULL);
	if (f < static_cast<float>(INT_MIN) || f > static_cast<float>(INT_MAX))
	{
		displayAll(0, 0, 0, 0, str);  // Not possible to convert to int
	}
	else
	{
		int			i = static_cast<int>(f);
		char		c = static_cast<char>(f);
		double		d = static_cast<double>(f);
		displayAll(c,i,f,d, str);
	}
}

bool	ScalarConverter::isNull(const std::string str)
{
	if (str == "0" || str == "0.0" || str == "0.0f" || str == "-0" || str == "-0.0" || str == "-0.0f")
		return (true);
	return (false);
}

/*------------------------------- Display -------------------------------*/



void	ScalarConverter::displayC(char c, std::string str)
{
	if (static_cast<int>(c) == 0 && !isNull(str))
		std::cout << "impossible" << std::endl;
	else if (c < 32 || c > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << c << "'" << std::endl;
}

void	ScalarConverter::displayI(int i, std::string str)
{
	if (i == 0 && !isNull(str))
		std::cout << "impossible" << std::endl;
	else
		std::cout << i << std::endl;
}

void	ScalarConverter::displayF(float f, std::string str)
{
	if (f == static_cast<double>(0) && !isNull(str))
		std::cout << "impossible" << std::endl;
	else
	{
		std::cout << f;
		if (static_cast<int>(f) == f)
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}

}

void	ScalarConverter::displayD(double d, std::string str)
{
	if (d == static_cast<double>(0) && !isNull(str))
		std::cout << "impossible" << std::endl;
	else
	{
		std::cout << d;
		if (static_cast<int>(d) == d)
			std::cout << ".0";
		std::cout << std::endl;
	}
}

void ScalarConverter::displayAll(char c, int i, float f, double d, std::string str)
{
	std::cout << "char: ";
	displayC(c, str);
	std::cout << "int: ";
	displayI(i, str);
	std::cout << "float: ";
	displayF(f, str);
	std::cout << "double: ";
	displayD(d, str);
}
