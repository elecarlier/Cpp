/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:18:47 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/05 17:59:41 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "\033[35m"
	<< "#FragTrap : "
	<< "Default Constructor called" << std::endl
	<< this->getName() << " has been created!" <<  "\033[0m" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "\033[35m"
	<< "#FragTrap : "
	<< "Constructor called" << std::endl
	<< this->getName() << " has been created!" <<  "\033[0m" << std::endl;

}

FragTrap::~FragTrap()
{
	std::cout << "\033[35m"
	<< "#FragTrap :"
	<< "Deconstructor called" << std::endl;
	//<< this->getName() << " is dead!" << "\033[0m" << std::endl;
}

// ScavTrap::ScavTrap(const ScavTrap &copy)
// {
// 	//std::cout << "\033[34m" << "Copy constructor called" << "\033[0m" << std::endl;
// 	*this = copy;
// }

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
	this->_name = copy.getName();
	this->_energyPoints = copy.getEnergypoint();
	this->_attackDamage = copy.getAttackdamage();
	this->_hitPoints = copy.getHitpoint();
	return (*this);
}


void FragTrap::highFivesGuys(void)
{
	std::cout << "High five??" << std::endl;
}