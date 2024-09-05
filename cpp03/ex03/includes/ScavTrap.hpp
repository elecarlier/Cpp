/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:23:24 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/05 18:27:04 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

/* Updating to virtual to avoid multiple instances of Claptrap */
class ScavTrap: virtual public ClapTrap
{
	private:

	public:
		ScavTrap();
		ScavTrap(std::string name);
		~ScavTrap();

		void attack(const std::string& target); //overwriting
		void guardGate();


};

#endif
