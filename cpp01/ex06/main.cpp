/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:36:07 by ecarlier          #+#    #+#             */
/*   Updated: 2024/08/22 14:51:26 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Harl.hpp"

int	main(int argc, char *argv[])
 {
	Harl harl;

	if (argc != 2)
	{
		std::cout << "Error: wrong arguments" << std::endl;
		return 1;
	}
	harl.complain(argv[1]);
	return 0;
	// harl.complain("DEBUG");
	// harl.complain("INFO");
	harl.complain("WARNING");
	// harl.complain("ERROR");
	return 0;
}
