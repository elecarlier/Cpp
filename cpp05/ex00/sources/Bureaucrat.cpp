/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:29:17 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/16 16:00:19 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default Bureaucrat"), _grade(150)
{
	std::cout << "\033[33m"
	<< "Bureaucrat Default Constructor with minimum grade called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	this->_grade = grade;
	std::cout << "\033[33m"
	<< "Bureaucrat Constructor called" <<  "\033[0m" << std::endl;

}

Bureaucrat::~Bureaucrat()
{
	std::cout << "\033[33m"
	<< "Bureaucrat Deconstructor called" <<  "\033[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	std::cout << "\033[34m" << "Bureaucrat Copy constructor called" << "\033[0m" << std::endl;
	*this = copy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	std::cout << "\033[35m" << "Bureaucrat Copy assignment operator called" << "\033[0m" << std::endl;
	// this->_name = copy._name;
	// this->_grade = copy._grade;
	return (*this);
}


/* --------------- Getters --------------- */
int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

/*--------------- Overload of << ---------------*/

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &i)
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade() << std::endl;
}
