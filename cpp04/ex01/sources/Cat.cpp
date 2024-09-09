/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 21:11:51 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/09 15:56:05 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/Cat.hpp"

Cat::Cat()
{
	this->_brain = new Brain();
	this->_type = "Cat";
	std::cout << "\033[32m"
	<< "#Cat :"
	<< "Default Constructor called" <<  "\033[0m"  << std::endl;
}


Cat::~Cat()
{
	delete this->_brain;
	std::cout << "\033[32m"
	<< "#Cat :"
	<< " Deconstructor called" <<  "\033[0m" << std::endl;
}

/* Directly calling Copy constructir from parent's class */
Cat::Cat(const Cat &copy) : Animal(copy)
{
	if (this != &copy)
	{
			this->_type = copy._type;
			this->_brain = new Brain(*(copy._brain));
	}

	std::cout << "\033[32m" << "Cat copy constructor called" << "\033[0m" << std::endl;
}

Cat &Cat::operator=(const Cat &copy)
{
	std::cout << "\033[32m" << "Cat assignation operator called" << "\033[0m" << std::endl;
	this->_type = copy._type;
	this->_brain = copy._brain;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "\033[32m" << "Miaou" << "\033[0m" << std::endl;
}
