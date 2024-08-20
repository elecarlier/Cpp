/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:42:33 by ecarlier          #+#    #+#             */
/*   Updated: 2024/08/20 20:36:11 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/HumanA.hpp"

HumanA::HumanA(std::string	name, Weapon weapon) : _name(name), _weapon(weapon)
{
	std::cout << "\033[33m" <<"HumanA constructor called" << "\033[0m" <<  std::endl;
}

HumanA::~HumanA()
{
	std::cout << "\033[32m" << "HumanA desconstructor called" << "\033[0m"  << std::endl;
}

void	HumanA::attack()
{
	std::string type = _weapon.getType();
	std::cout << this->_name << " attacks with their " << type << std::endl;
}
