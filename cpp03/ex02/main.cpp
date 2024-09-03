/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:26:39 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/03 21:34:37 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ClapTrap.hpp"
#include "includes/ScavTrap.hpp"
#include "includes/FragTrap.hpp"

int main(void)
{
	{
		FragTrap	a("Pierre");
		std::cout << a;
		a.attack("Target");
		// for (int i = 0; i < 99; i++)
		// 	a.attack("Target");
		std::cout << a;
		a.beRepaired(5);
		a.beRepaired(5);
		a.attack("Target");
		std::cout << a;
	}
	std::cout << std::endl;
	{
		FragTrap	a("Antoine");
		std::cout << a;
		a.takeDamage(150);
		std::cout << a;
		a.attack("Target");
		a.beRepaired(5);
		std::cout << a;
	}
	std::cout << std::endl;
	{
		FragTrap	a("Jean");
		FragTrap	b(a);
		FragTrap	c = a;
		a.highFivesGuys();
		b.highFivesGuys();
		c.highFivesGuys();
		std::cout << a << b << c;
	}
}
