/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:38:07 by ecarlier          #+#    #+#             */
/*   Updated: 2024/08/29 17:46:39 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"


ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDammage = 10;
	//std::cout << "\033[33m" << "Default constructor called" << "\033[0m" <<  std::endl;
}

ClapTrap::~ClapTrap()
{
	//std::cout << "\033[32m" << "Desconstructor called" << "\033[0m"  << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	//std::cout << "\033[34m" << "Copy constructor called" << "\033[0m" << std::endl;
	*this = copy;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	//std::cout << "\033[35m" << "Copy assignment operator called" << "\033[0m" << std::endl;

}
