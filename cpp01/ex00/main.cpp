/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:29:42 by ecarlier          #+#    #+#             */
/*   Updated: 2024/08/28 15:26:46 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Zombie.hpp"

int main(void)
{
	Zombie *zombie_1;

	zombie_1 = newZombie("Jean");
	zombie_1->announce();

	randomChump("Pierre");
	delete zombie_1;
}
