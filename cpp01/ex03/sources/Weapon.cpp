/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:00:32 by ecarlier          #+#    #+#             */
/*   Updated: 2024/08/20 19:49:49 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon(std::string type)
{
	_type = type;
	std::cout << "\033[33m" <<"Weapon constructor called" << "\033[0m" <<  std::endl;
}

Weapon::~Weapon()
{
	std::cout << "\033[32m" <<"Weapon deconstructor called" << "\033[0m" <<  std::endl;
}

const std::string&	Weapon::getType()
{
	return (this->_type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}
