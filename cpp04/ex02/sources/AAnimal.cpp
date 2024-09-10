/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 21:11:44 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/09 15:54:51 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AAnimal.hpp"

AAnimal::AAnimal()
{
	this->_type = "Random AAnimal";
	std::cout << "\033[33m"
	<< "#AAnimal :"
	<< "Default Constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type)
{
	this->_type = type;
	std::cout << "\033[33m"
	<< "#AAnimal :"
	<< " Constructor called" <<  "\033[0m" << std::endl;

}

AAnimal::~AAnimal()
{
	std::cout << "\033[33m"
	<< "#AAnimal :"
	<< " Deconstructor called" <<  "\033[0m" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy)
{
	std::cout << "\033[34m" << "AAnimal copy constructor called" << "\033[0m" << std::endl;
	*this = copy;
}

AAnimal &AAnimal::operator=(const AAnimal &copy)
{
	std::cout << "\033[35m" << "Copy assignment operator called" << "\033[0m" << std::endl;
	this->_type = copy._type;
	return (*this);
}

void	AAnimal::setType(std::string type)
{
	this->_type = type;
}

std::string	AAnimal::getType() const
{
	return (this->_type);
}
