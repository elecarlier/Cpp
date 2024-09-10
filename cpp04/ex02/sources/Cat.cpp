/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 21:11:51 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/10 16:32:54 by ecarlier         ###   ########.fr       */
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


Cat::Cat(std::string const type) : AAnimal(type)
{
	this->_type = type;
	this->_brain = new Brain();
	std::cout << "\033[32m"
	<< "#Cat :"
	 << "Parametric constructor called" <<  "\033[0m" << std::endl;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "\033[32m"
	<< "#Cat :"
	<< " Deconstructor called" <<  "\033[0m" << std::endl;
}

/* Directly calling Copy constructor from parent's class */
Cat::Cat(const Cat &copy) : AAnimal(copy)
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
	if (this != &copy)  // Avoid self-assignment
	{
		delete this->_brain;
		this->_brain = new Brain(*(copy._brain));  // Deep copy of the Brain
		this->_type = copy._type;
	}

	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "\033[32m" << "Miaou" << "\033[0m" << std::endl;
}
