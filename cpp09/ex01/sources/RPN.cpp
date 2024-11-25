/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:04:06 by ecarlier          #+#    #+#             */
/*   Updated: 2024/11/25 21:19:33 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

RPN::RPN()
{
	#ifdef DEBUG_MODE
		std::cout << "\033[33m" << "Default constructor called" << "\033[0m" << std::endl;
	#endif
}

RPN::RPN(const std::string& RPNExpression)
{
	try
	{
		validate_input(RPNExpression);
		calculate_RNP(RPNExpression);
		std::cout << this->_numbers.top() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	#ifdef DEBUG_MODE
		std::cout << "\033[33m" << "Default constructor called" << "\033[0m" << std::endl;
	#endif
}

RPN::~RPN()
{
	#ifdef DEBUG_MODE
		std::cout << "\033[32m" << "Destructor called" << "\033[0m" << std::endl;
	#endif
}

/*not done*/
RPN::RPN(const RPN &copy)
{
	(void)copy;
	#ifdef DEBUG_MODE
		std::cout << "\033[34m" << "Copy constructor called" << "\033[0m" << std::endl;
	#endif
}

bool	RPN::isoperand( const char& c ) {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

void RPN::calc_op(const char& c)
{
	if (this->_numbers.empty())
		throw RPN::InvalidRPNExpression();
	int arg1 = this->_numbers.top();
	_numbers.pop();
	if (this->_numbers.empty())
		throw RPN::InvalidRPNExpression();
	int arg2 = this->_numbers.top();
	_numbers.pop();

	switch(c)
	{
		case '+':
			this->_numbers.push(arg1 + arg2);
			break;
		case '-':
			this->_numbers.push(arg2 - arg1);
			break;
		case '*':
			this->_numbers.push(arg2 * arg1);
			break;
		case '/':
			if (arg1 == 0)
				throw RPN::InvalidRPNExpression();
			this->_numbers.push(arg2 / arg1);
			break;
	}
}

void RPN::calculate_RNP(const std::string& RPNExpression)
{
	size_t size_RPN;
	char c;
	size_RPN = RPNExpression.size();

	for (size_t i = 0; i <size_RPN; i++ )
	{
		c = RPNExpression[i];
		if (isdigit(c))
			this->_numbers.push(c - '0');
		else if (isspace(c))
			continue;
		else if (isoperand(c))
			calc_op(c);
		else
			throw (RPN::InvalidRPNExpression());
	}
	if (this->_numbers.size() != 1)
		throw RPN::InvalidRPNExpression();

}

void RPN::validate_input(const std::string& RPNExpression)
{
	size_t size_RPN;
	char c;

	size_RPN = RPNExpression.size();
	for (size_t i = 0; i <size_RPN; i++ )
	{
		c = RPNExpression[i];
		if (!isdigit(c) && !isoperand(c) && !isspace(c))
		{
			throw RPN::InvalidRPNExpression();
		}
	}

}
/*not done*/
RPN &RPN::operator=(const RPN &copy)
{
	(void)copy;
	#ifdef DEBUG_MODE
		std::cout << "\033[35m" << "Copy assignment operator called" << "\033[0m" << std::endl;
	#endif
	return *this;
}


const char*	RPN::InvalidRPNExpression::what() const throw()
{
	return ("Invalid RPN expression");
}
const char*	RPN::zeroDivison::what() const throw()
{
	return ("Division by zero is not allowed");
}
const char*	RPN::unexpectedError::what() const throw()
{
	return ("Unexpected error occurred in RPN calculation");
}
