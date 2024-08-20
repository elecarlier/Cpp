/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 18:13:10 by ecarlier          #+#    #+#             */
/*   Updated: 2024/08/20 18:45:59 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;


	std::cout
	<< "Memory address... "  << std::endl
	<< "of the string       : " << "\033[34m" << &str << "\033[0m" << std::endl
	<< "held by stringPTR   : " << "\033[34m" << stringPTR << "\033[0m" <<std::endl
	<< "held by stringREF   : " << "\033[34m"  << &stringREF << "\033[0m" << std::endl;

	std::cout
	<< "Value ... "  << std::endl
	<< "of the string             : " << "\033[34m" << str << "\033[0m" << std::endl
	<< "pointed to by stringPTR   : " << "\033[34m" << *stringPTR << "\033[0m" <<std::endl
	<< "pointed to by stringREF   : " << "\033[34m"  << stringREF << "\033[0m" << std::endl;


	// std::cout
	// << "Memory address... "  << std::endl
	// << "of the string  : " << "\033[34m" << &str << "\033[0m" << std::endl
	// << "of stringPTR   : " << "\033[33m" << &stringPTR << "\033[0m" <<std::endl
	// << "of by stringREF: " << "\033[34m"  << &stringREF << "\033[0m" << std::endl
	// << "Value ... "  << std::endl
	// << "of the string  : " << "\033[34m" << str << "\033[0m" << std::endl
	// << "of stringPTR   : " << "\033[33m" << stringPTR << "\033[0m" <<std::endl
	// << "of stringREF   : " << "\033[34m"  << stringREF << "\033[0m" << std::endl;

	return (0);

}
