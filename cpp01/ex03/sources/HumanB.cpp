/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:42:35 by ecarlier          #+#    #+#             */
/*   Updated: 2024/08/20 20:23:17 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string	name)
{
	this->_name = name;
	this->_weapon = NULL;
	std::cout << "\033[33m" << "HumanB constructor called" << "\033[0m" <<  std::endl;
}

HumanB::~HumanB()
{
	std::cout << "\033[32m"<< "HumanB desconstructor called" << "\033[0m"  << std::endl;
}

void	HumanB::setWeapon(Weapon weapon)
{
	this->_weapon = &weapon;
}

void	HumanB::attack()
{
	if (this->_weapon == NULL)
	{
		std::cout << this->_name << " tried to attacks but has no weapon... " << std::endl;
	}
	else
	{
		std::string	type = this->_weapon->getType();
		std::cout << this->_name << " attacks with their " << type << std::endl;
	}

}
