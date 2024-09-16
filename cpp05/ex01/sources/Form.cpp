/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:39:41 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/16 19:58:27 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form() : _name("Default"), _signed(false), _S_grade(42), _E_grade(42)
{
	std::cout << "\033[34m"
	<< "Form Default Constructor called" <<  "\033[0m" << std::endl;
}


Form::Form(std::string name, int sign_grade, int exec_grade) : _name(name), _signed(false), _S_grade(sign_grade), _E_grade(exec_grade)
{
	if (_S_grade < 1)
		throw Form::GradeTooHighException();
	else if (_S_grade > 150)
		throw Form::GradeTooLowException();
	if (_E_grade < 1)
		throw Form::GradeTooHighException();
	else if (_E_grade > 150)
		throw Form::GradeTooLowException();

	std::cout << "\033[34m"
	<< "Form Constructor called" <<  "\033[0m" << std::endl;

}

Form::~Form()
{
	std::cout << "\033[34m"
	<< "Form Deconstructor called" <<  "\033[0m" << std::endl;
}

Form::Form(const Form &copy) : _name(copy._name), _signed(copy._signed), _S_grade(copy._S_grade), _E_grade(copy._E_grade)
{
	std::cout << "\033[34m" << "Form Copy constructor called" << "\033[0m" << std::endl;
	*this = copy;
}

/*--------------- Methods ---------------*/

void	Form::beSigned(Bureaucrat bureaucrat)
{
	if (_signed)
		throw Form::AlreadySignedException();
	if (bureaucrat.getGrade() > this->_S_grade )
		throw Form::GradeTooLowException();
	else
		this->_signed = true;
}

/* --------------- Expections handling --------------- */

const char* Form::GradeTooHighException::what() const throw ()
{
	return ("Trowing exception : grade too high");
}

const char* Form::GradeTooLowException::what() const throw ()
{
	return ("Trowing exception : grade too low");
}

const char* Form::AlreadySignedException::what() const throw ()
{
	return ("Trowing exception : form already signed");
}

/* --------------- Getters --------------- */

int		Form::getSGrade() const
{
	return (this->_S_grade);
}

int		Form::getEGrade() const
{
	return (this->_E_grade);
}

std::string	Form::getName() const
{
	return (this->_name);
}

bool		Form::getSigned() const
{
	return (this->_signed);
}

/*--------------- Overload ---------------*/

Form &Form::operator=(const Form &copy)
{
	std::cout << "\033[35m" << "Form Copy assignment operator called" << "\033[0m" << std::endl;
	if (this != &copy)
	{
		this->_signed = copy.getSigned();
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, Form const &i)
{

	o << i.getName() << std::endl
	<< ", garde required to sign : " << i.getSGrade() << std::endl
	<< ", grade required to execute : " << i.getEGrade() << std::endl
	<< ", signed status : " << (i.getSigned() ? "Signed" : "Not Signed") << std::endl;
	return (o);
}
