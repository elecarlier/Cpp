/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 21:11:43 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/10 14:13:42 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog()
{
	this->_brain = new Brain();
	this->_type = "Dog";
	std::cout << "\033[35m"
	<< "#Dog :"
	<< "Default Constructor called" <<  "\033[0m" << std::endl;
}

Dog::Dog(std::string const type) : Animal(type)
{
	this->_type = type;
	this->_brain = new Brain();
	std::cout << "\033[35m"
	<< "#Dog :"
	<< "Parametric constructor called" << std::endl;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "\033[35m"
	<< "#Dog :"
	<< " Deconstructor called" <<  "\033[0m"  << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	if (this != &copy)
	{
		this->_type = copy._type;
		this->_brain = new Brain(*(copy._brain));
	}
	std::cout << "\033[35m" << "Dog copy constructor called" << "\033[0m" << std::endl;

}

Dog &Dog::operator=(const Dog &copy)
{
	std::cout << "\033[35m" <<  "Dog assignation operator called"<< "\033[0m" << std::endl;
	if (this != &copy)  // Avoid self-assignment
	{
		delete this->_brain;
		this->_brain = new Brain(*(copy._brain));  // Deep copy of the Brain
		this->_type = copy._type;
	}

	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "\033[35m" << "Wouf" << "\033[0m" << std::endl;
}
