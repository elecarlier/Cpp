/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:09:47 by ecarlier          #+#    #+#             */
/*   Updated: 2024/08/20 17:32:00 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Zombie.hpp"

int main(void)
{
	int	N = 4;
	Zombie *horde = zombieHorde(N, "Pierre");

	for (int i = 0; i < N; i++)
	{
		horde[i].announce();
	}
	delete[] horde;

	return 0;
}
