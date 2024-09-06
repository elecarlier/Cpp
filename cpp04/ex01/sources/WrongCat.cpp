/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:50:11 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/06 16:52:34 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat()
{
	this->_type = "WrongCat";
	std::cout << "\033[32m"
	<< "#WrongCat :"
	<< "Default Constructor called" <<  "\033[0m"  << std::endl;
}


WrongCat::~WrongCat()
{
	std::cout << "\033[32m"
	<< "#WrongCat :"
	<< " Deconstructor called" <<  "\033[0m" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy)
{
	std::cout << "\033[32m" << "Copy constructor called" << "\033[0m" << std::endl;
	*this = copy;
}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
	std::cout << "\033[32m" << "Copy assignment operator called" << "\033[0m" << std::endl;
	this->_type = copy._type;
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "\033[32m" << "Wrong Miaou" << "\033[0m" << std::endl;
}
