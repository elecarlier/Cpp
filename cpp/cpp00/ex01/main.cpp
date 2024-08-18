/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:32:03 by ecarlier          #+#    #+#             */
/*   Updated: 2024/08/18 16:34:46 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/MyAwesomePhonebook.hpp"

int	main()
{
	PhoneBook book;
	std::string input;

	while (1)
	{
		std::cout << "Please enter ADD, SEARCH or EXIT" << std::endl;
		std::cin >> input;

		if (input == "ADD" || input == "add")
		{
			book.add_contact();
		}
		else
			std::cout << "Invalid option, please try again." << std::endl;


	}
}
