/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:29:17 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/17 13:03:18 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << "\033[34m"
	<< "Bureaucrat Default Constructor with minimum grade called" <<  "\033[0m" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;

	std::cout << "\033[34m"
	<< "Bureaucrat Constructor called" <<  "\033[0m" << std::endl;

}

Bureaucrat::~Bureaucrat()
{
	std::cout << "\033[34m"
	<< "Bureaucrat Deconstructor called\n" <<  "\033[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	//std::cout << "\033[34m" << "Bureaucrat Copy constructor called" << "\033[0m" << std::endl;
	*this = copy;
}

/*--------------- Methods ---------------*/

void Bureaucrat::incrementGrade()
{
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

void Bureaucrat::signForm(AForm & AForm)
{
	if (AForm.getSigned())
		std::cout << this->getName() << " couldn’t sign " << AForm.getName() << " because the AForm is already signed"  << std::endl;
	else
	{
		try
		{
			AForm.beSigned(*this);
			std::cout << this->getName() << " signed " << AForm.getName() << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << this->getName() << " couldn’t sign " << AForm.getName() << " because his/her grade is too low"  << std::endl;
		}
	}


}

/* --------------- Expections handling --------------- */

const char* Bureaucrat::GradeTooHighException::what() const throw ()
{
	return ("Trowing exception : grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw ()
{
	return ("Trowing exception : grade too low");
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

/*--------------- Overload ---------------*/

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	//std::cout << "\033[35m" << "Bureaucrat Copy assignment operator called" << "\033[0m" << std::endl;
	if (this != &copy)
	{
		this->_grade = copy.getGrade();
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &i)
{

	o << i.getName() << ", bureaucrat grade " << i.getGrade() << std::endl;
	return (o);
}
