/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:23:26 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/05 20:18:33 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	this->_name = "ScavTrap Anonymous";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "\033[34m"
	<< "#ScavTrap : "
	<< "Default Constructor called" << std::endl
	<< this->getName() << " has been created!" <<  "\033[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	// this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "\033[34m"
	<< "#ScavTrap : "
	<< "Constructor called" << std::endl
	<< this->getName() << " has been created!" <<  "\033[0m" << std::endl;

}

ScavTrap::~ScavTrap()
{
	std::cout << "\033[34m"
	<< "#ScavTrap :"
	<< "Deconstructor called" << std::endl;
	//<< this->getName() << " is dead!" << "\033[0m" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap &copy)
{
	//std::cout << "\033[34m" << "Copy constructor called" << "\033[0m" << std::endl;
	*this = copy;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
	//std::cout << "\033[35m" << "Copy assignment operator called" << "\033[0m" << std::endl;
	this->_name = copy.getName();
	this->_energyPoints = copy.getEnergypoint();
	this->_attackDamage = copy.getAttackdamage();
	this->_hitPoints = copy.getHitpoint();
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	std::cout << "\033[34m"
	<< "#ScavTrap : " <<  "\033[0m";
	if (this->_energyPoints == 0)
	{
		std::cout << this->getName() << " has no ernergy points left to attack" << std::endl;
	}
	else if (this->_hitPoints == 0)
	{
		std::cout << this->getName() << " has no hit points left to attack" << std::endl;
	}
	else
	{
		this->setEnergypoint(_energyPoints - 1);
		std::cout << "\033[34m"  << this->getName() << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << "\033[0m" ;
		std::cout << "\033[3m" << " [ Total of hit points left : " << this->_hitPoints << " ]" << "\033[0m" << std::endl;
	}
}

void ScavTrap::guardGate()
{
	std::cout << "\033[34m" << "ScavTrap is now in Gate keeper mode\n" << "\033[0m";
}
