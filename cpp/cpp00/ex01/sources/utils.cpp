/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:54:28 by ecarlier          #+#    #+#             */
/*   Updated: 2024/08/18 16:42:29 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MyAwesomePhonebook.hpp"

std::string	get_input(std::string prompt)
{
	std::string	input;

	std::cout << "\nPlease enter the " << prompt;
	while(input.empty())
	{
		if (std::cin.peek() == '\n') std::cin.ignore();
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << "\nField " << prompt << " can not be empty. Please try again: ";
	}
	return (input);
}
