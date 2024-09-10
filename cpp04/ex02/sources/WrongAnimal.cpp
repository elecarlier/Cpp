/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:50:17 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/09 18:36:44 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->_type = "Random wrong Animal";
	std::cout << "\033[36m"
	<< "#WrongAnimal :"
	<< "Default Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
	this->_type = type;
	std::cout << "\033[36m"
	<< "#WrongAnimal :"
	<< " Constructor called" <<  "\033[0m" << std::endl;

}

WrongAnimal::~WrongAnimal()
{
	std::cout << "\033[36m"
	<< "#WrongAnimal :"
	<< " Deconstructor called" <<  "\033[0m" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "\033[34m" << "Copy constructor called" << "\033[0m" << std::endl;
	*this = copy;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
	std::cout << "\033[35m" << "Copy assignment operator called" << "\033[0m" << std::endl;
	this->_type = copy._type;
	return (*this);
}

void	WrongAnimal::makeSound() const
{
	std::cout <<  "\033[33m" << "WrongAAnimal sound" << "\033[0m" <<  std::endl;
}

void	WrongAnimal::setType(std::string type)
{
	this->_type = type;
}

std::string	WrongAnimal::getType() const
{
	return (this->_type);
}
