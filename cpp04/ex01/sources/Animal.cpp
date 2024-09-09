/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 21:11:44 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/09 15:54:51 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal()
{
	this->_type = "Random animal";
	std::cout << "\033[33m"
	<< "#Animal :"
	<< "Default Constructor called" << std::endl;
}

Animal::Animal(std::string type)
{
	this->_type = type;
	std::cout << "\033[33m"
	<< "#Animal :"
	<< " Constructor called" <<  "\033[0m" << std::endl;

}

Animal::~Animal()
{
	std::cout << "\033[33m"
	<< "#Animal :"
	<< " Deconstructor called" <<  "\033[0m" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	std::cout << "\033[34m" << "Animal copy constructor called" << "\033[0m" << std::endl;
	*this = copy;
}

Animal &Animal::operator=(const Animal &copy)
{
	std::cout << "\033[35m" << "Copy assignment operator called" << "\033[0m" << std::endl;
	this->_type = copy._type;
	return (*this);
}

void	Animal::makeSound() const
{
	std::cout <<  "\033[33m" << "Animal sound" << "\033[0m" <<  std::endl;
}


void	Animal::setType(std::string type)
{
	this->_type = type;
}

std::string	Animal::getType() const
{
	return (this->_type);
}
