/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:41:39 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/05 20:25:39 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	this->_hitPoints = FragTrap::_hit;
	this->_energyPoints = ScavTrap::_energy;
	this->_attackDamage = FragTrap::_damage;

	std::cout << "\033[36m"
	<< "#DiamondTrap : "
	<< "Default constructor called" << std::endl
	<< this->getName() << " has been created!" <<  "\033[0m" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) :  ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	this->_name = name;
	this->_hitPoints = FragTrap::_hit;
	this->_energyPoints = ScavTrap::_energy;
	this->_attackDamage = FragTrap::_damage;

	std::cout << "\033[36m"
	<< "#DiamondTrap : "
	<< "Constructor called" << std::endl
	<< this->getName() << " has been created!" <<  "\033[0m" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy)
{
	//std::cout << "\033[34m" << "Copy constructor called" << "\033[0m" << std::endl;
	*this = copy;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy)
{
	//std::cout << "\033[35m" << "Copy assignment operator called" << "\033[0m" << std::endl;
	this->ClapTrap::_name = copy.ClapTrap::_name;
	this->_name = copy._name;
	this->_energyPoints = copy._energyPoints;
	this->_attackDamage = copy._attackDamage;
	this->_hitPoints = copy._hitPoints;
	return (*this);
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
