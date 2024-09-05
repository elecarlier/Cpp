/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:26:39 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/05 20:26:40 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ClapTrap.hpp"
#include "includes/ScavTrap.hpp"
#include "includes/FragTrap.hpp"
#include "includes/DiamondTrap.hpp"

int main(void)
{
	{
		DiamondTrap	a("Pierre");
		std::cout << a;
		// for (int i = 0; i < 49; i++)
		// 	a.attack("Target");
		//std::cout << a;
		a.beRepaired(5);
		a.attack("Target");
		std::cout << a;
	}
	std::cout << std::endl;
	{
		DiamondTrap	a("Jean");
		std::cout << a;
		a.takeDamage(150);
		std::cout << a;
		a.attack("Target");
		a.beRepaired(5);
		std::cout << a;
	}
	std::cout << std::endl;
	{
		DiamondTrap	a("Jacques");
		DiamondTrap	b(a);
		DiamondTrap	c = a;
		a.whoAmI();
		b.whoAmI();
		c.whoAmI();
		std::cout << a << b << c;
	}
}
