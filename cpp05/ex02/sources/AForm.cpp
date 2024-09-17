/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:39:41 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/16 19:58:27 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

AForm::AForm() : _name("Default"), _signed(false), _S_grade(42), _E_grade(42)
{
	std::cout << "\033[34m"
	<< "AForm Default Constructor called" <<  "\033[0m" << std::endl;
}


AForm::AForm(std::string name, int sign_grade, int exec_grade) : _name(name), _signed(false), _S_grade(sign_grade), _E_grade(exec_grade)
{
	if (_S_grade < 1)
		throw AForm::GradeTooHighException();
	else if (_S_grade > 150)
		throw AForm::GradeTooLowException();
	if (_E_grade < 1)
		throw AForm::GradeTooHighException();
	else if (_E_grade > 150)
		throw AForm::GradeTooLowException();

	std::cout << "\033[34m"
	<< "Form Constructor called" <<  "\033[0m" << std::endl;

}

AForm::~AForm()
{
	std::cout << "\033[34m"
	<< "AForm Deconstructor called" <<  "\033[0m" << std::endl;
}

AForm::AForm(const AForm &copy) : _name(copy._name), _signed(copy._signed), _S_grade(copy._S_grade), _E_grade(copy._E_grade)
{
	std::cout << "\033[34m" << "AForm Copy constructor called" << "\033[0m" << std::endl;
	*this = copy;
}

/*--------------- Methods ---------------*/

void	AForm::beSigned(Bureaucrat bureaucrat)
{
	if (_signed)
		throw AForm::AlreadySignedException();
	if (bureaucrat.getGrade() > this->_S_grade )
		throw AForm::GradeTooLowException();
	else
		this->_signed = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!_signed)
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->_E_grade )
		throw AForm::GradeTooLowException();
}


/* --------------- Expections handling --------------- */

const char* AForm::GradeTooHighException::what() const throw ()
{
	return ("Trowing exception : grade too high");
}

const char* AForm::GradeTooLowException::what() const throw ()
{
	return ("Trowing exception : grade too low");
}

const char* AForm::AlreadySignedException::what() const throw ()
{
	return ("Trowing exception : Form already signed");
}

const char* AForm::NotSignedException::what() const throw ()
{
	return ("Trowing exception : Form is not signed");
}
/* --------------- Getters --------------- */

int		AForm::getSGrade() const
{
	return (this->_S_grade);
}

int		AForm::getEGrade() const
{
	return (this->_E_grade);
}

std::string	AForm::getName() const
{
	return (this->_name);
}

bool		AForm::getSigned() const
{
	return (this->_signed);
}

/*--------------- Overload ---------------*/

AForm &AForm::operator=(const AForm &copy)
{
	std::cout << "\033[35m" << "AForm Copy assignment operator called" << "\033[0m" << std::endl;
	if (this != &copy)
	{
		this->_signed = copy.getSigned();
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, AForm const &i)
{
	o << i.getName() << std::endl
	<< ", garde required to sign : " << i.getSGrade() << std::endl
	<< ", grade required to execute : " << i.getEGrade() << std::endl
	<< ", signed status : " << (i.getSigned() ? "Signed" : "Not Signed") << std::endl;
	return (o);
}
