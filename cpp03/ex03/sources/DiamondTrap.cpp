/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:41:39 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/05 17:59:55 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) :  ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap()
{
	this->_name = name;
	FragTrap::setHitpoint(100);
	ScavTrap::setEnergypoint(50);
	FragTrap::setAttackdamage(30);
	std::cout << "\033[36m"
	<< "#DiamondTrap : "
	<< "Constructor called" << std::endl
	<< this->getName() << " has been created!" <<  "\033[0m" << std::endl;

}

DiamondTrap::~DiamondTrap()
{
	std::cout << "\033[36m"
	<< "#DiamondTrap :"
	<< "Deconstructor called" << std::endl;
	//<< this->getName() << " is dead!" << "\033[0m" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "\033[36m"
	<< "#DiamondTrap :"
	<< "I am DiamondTrap named " << this->_name
	<< " and my ClapTrap name is " << ClapTrap::getName() << std::endl;
}
