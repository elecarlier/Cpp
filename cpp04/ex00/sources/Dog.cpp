/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 21:11:43 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/09 18:21:07 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog(): Animal()
{
	this->_type = "Dog";
	std::cout << "\033[35m"
	<< "#Dog :"
	<< "Default Constructor called" <<  "\033[0m" << std::endl;
}

Dog::~Dog()
{
	std::cout << "\033[35m"
	<< "#Dog :"
	<< " Deconstructor called" <<  "\033[0m"  << std::endl;
}
Dog::Dog(std::string const type) : Animal(type)
{
	this->_type = type;

	std::cout << "\033[35m"
	<< "#Dog :"
	<< "Dog parametric constructor called" <<  "\033[0m" << std::endl;
}

Dog::Dog(const Dog &copy)
{
	if (this != &copy)
		*this = copy;
	std::cout << "\033[35m" << "Dog copy constructor called" << "\033[0m" << std::endl;
	*this = copy;
}

Dog &Dog::operator=(const Dog &copy)
{
	std::cout << "\033[35m" << "Dog assignation operator called" << "\033[0m" << std::endl;
	this->_type = copy._type;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "\033[35m" << "Wouf" << "\033[0m" << std::endl;
}
