/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:41:59 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/05 17:37:42 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

class DiamondTrap: public FragTrap, public ScavTrap
{
	private:
		std::string	_name; //diff than ClapTrap's name

	public:
		//DiamondTrap();
		DiamondTrap(std::string name);
		~DiamondTrap();

		void	whoAmI();

};

#endif