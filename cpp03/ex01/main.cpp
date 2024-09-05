/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:32:57 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/05 18:20:52 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ClapTrap.hpp"
#include "includes/ScavTrap.hpp"

int main(void)
{
	{
		ScavTrap	a("Jean");
		std::cout << a;
		a.beRepaired(5);
		std::cout << a;
		a.attack("Target");
		std::cout << a;
	}
	std::cout << std::endl;
	{
		ScavTrap	a("Pierre");
		std::cout << a;
		a.takeDamage(150);
		std::cout << a;
		a.attack("Target");
		a.beRepaired(5);
		std::cout << a;
	}
	std::cout << std::endl;
	{
		ScavTrap	a("Antoine");
		ScavTrap	b(a);
		ScavTrap	c = a;
		a.guardGate();
		b.guardGate();
		c.guardGate();
		std::cout << a << b << c;
	}
}
