/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:32:57 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/03 19:13:09 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ClapTrap.hpp"


int main(void)
{
	{
		ClapTrap	a("Jean");
		std::cout << a;
		a.attack("Target");
		a.beRepaired(5);
		std::cout << a;
		a.attack("Target");
		a.beRepaired(5);
		std::cout << a;
	}
	std::cout << std::endl;
	{
		ClapTrap	a("Pierre");
		std::cout << a;
		for (size_t i = 0; i < 11; i++)
		{
			a.attack("ClapTrap Anonymous");
		}
		std::cout << a;
	}
	std::cout << std::endl;
	{
		ClapTrap	a("Antoine");
		ClapTrap	b(a); //creating a claptrap with copy constructor
		ClapTrap	c = a;
		std::cout << a << b << c;
	}
}
