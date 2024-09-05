/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:18:47 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/05 18:28:15 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	this->_name = "FragTrap Anonymous";
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
	<< "Deconstructor called" << std::endl
	<< this->getName() << " is dead!" << "\033[0m" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "High five??" << std::endl;
}
