/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:54:28 by ecarlier          #+#    #+#             */
/*   Updated: 2024/08/18 19:36:20 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MyAwesomePhonebook.hpp"

std::string	get_input(std::string prompt)
{
	std::string	input;

	std::cout << "\033[1m" << "Please enter "  << prompt << "\033[0m" ;
	while(input.empty())
	{
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::cout << "\033[31m" << "Field can not be empty. Please try again: " << "\033[0m" << std::endl;
			std::cout << "\033[1m" << "Please enter "  << prompt << "\033[0m";
		}
	}
	return (input);
}

std::string truncate_str(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0,9).append("."));
	return (str);
}
