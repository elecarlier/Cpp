/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:46:35 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/17 17:27:29 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default Shrubbery Form", 145, 137), _target("Default Target")
{
	std::cout << "\033[33m" << "Shrubbery Default constructor called" << "\033[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Default Shrubbery Form", 145, 137), _target(target)
{
	std::cout << "\033[33m" << "Shrubbery constructor called" << "\033[0m" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "\033[32m" << "Shrubbery Destructor called" << "\033[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
{
	std::cout << "\033[34m" << "Shrubbery Copy constructor called" << "\033[0m" << std::endl;
	*this = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	std::cout << "\033[35m" << "Shrubbery Copy assignment operator called" << "\033[0m" << std::endl;
	if (this != &copy)
	{
		this->_target = copy._target;
	}
	return *this;
}



std::string ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}
