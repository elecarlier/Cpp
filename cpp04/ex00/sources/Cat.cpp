/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 21:11:51 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/09 18:19:04 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/Cat.hpp"

Cat::Cat()
{
	this->_type = "Cat";
	std::cout << "\033[32m"
	<< "#Cat :"
	<< "Default Constructor called" <<  "\033[0m"  << std::endl;
}

Cat::Cat(std::string const type) : Animal(type)
{
	this->_type = type;
	std::cout << "\033[32m"
	<< "#Cat :"
	<< "Cat parametric constructor called" <<  "\033[0m" << std::endl;
}

Cat::~Cat()
{
	std::cout << "\033[32m"
	<< "#Cat :"
	<< " Deconstructor called" <<  "\033[0m" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	if (this != &copy)
		*this = copy;
	std::cout << "\033[32m" << "Cat copy constructor called" << "\033[0m" << std::endl;
}

Cat &Cat::operator=(const Cat &copy)
{
	std::cout << "\033[32m" << "Cat assignation operator called" << "\033[0m" << std::endl;

	this->_type = copy._type;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "\033[32m" << "Miaou" << "\033[0m" << std::endl;
}
