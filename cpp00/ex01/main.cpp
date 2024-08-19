/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:32:03 by ecarlier          #+#    #+#             */
/*   Updated: 2024/08/18 22:20:28 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/MyAwesomePhonebook.hpp"

int	main()
{
	PhoneBook book;
	std::string input;

	while (1)
	{
		std::cout << "\033[1m" << "Please enter ADD, SEARCH or EXIT" << "\033[0m" << std::endl;
		std::cin >> input;

		if (input == "ADD")
			book.add_contact();
		else if (input == "SEARCH")
			book.search();
		else if (input == "EXIT")
			return (0);
		else
			std::cout << "\033[31m" << "Invalid option, please try again..." << "\033[0m" <<  std::endl;


	}
}
