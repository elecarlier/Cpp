/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:32:21 by ecarlier          #+#    #+#             */
/*   Updated: 2024/08/20 17:32:29 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "\033[33m" << this->_name << "constructor called" << "\033[0m" <<  std::endl;
}

Zombie::~Zombie()
{
	std::cout << "\033[32m" << this->_name << " desconstructor called" << "\033[0m"  << std::endl;
}

void	Zombie::setName(const std::string &name)
{
	this->_name = name;
}

void	Zombie::announce()
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

