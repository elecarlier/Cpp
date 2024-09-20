/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:35:33 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/20 12:19:43 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

Intern::Intern()
{
	std::cout << "\033[33m" << "Default constructor called" << "\033[0m" << std::endl;
}

Intern::~Intern()
{
	std::cout << "\033[32m" << "Destructor called" << "\033[0m" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	std::cout << "\033[34m" << "Copy constructor called" << "\033[0m" << std::endl;
	*this = copy;
}

Intern &Intern::operator=(const Intern &copy)
{
	std::cout << "\033[35m" << "Copy assignment operator called" << "\033[0m" << std::endl;
	(void)copy;
	return (*this);
}


AForm*	Intern::makeForm(std::string name, std::string target)
{
	std::string formNames[3] = {"SHRUBBERY CREATION", "ROBOTOMY REQUEST", "PRESIDENTIAL PARDON"};
	AForm *(Intern::*funcPtr[3])(std::string &) = { &Intern::makeSrubbery, &Intern::makeRobotomy, &Intern::makePresidential};

	std::string upName = stringToupper(name);

	for (int i = 0; i < 3 ; i++)
	{
		if (formNames[i] == upName)
		{
			std::cout << "Intern creates " << name << std::endl;
			return (this->*funcPtr[i])(target);
		}
	}
	throw Intern::CreateFile();
}

std::string stringToupper(std::string str)
{
	std::string new_str;
	for (std::string::size_type i=0; i < str.length(); i++)
	{
		new_str += std::toupper(str[i]);
	}
	return (new_str);
}


AForm *Intern::makeSrubbery(std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeRobotomy(std::string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makePresidential(std::string &target)
{
	return (new PresidentialPardonForm(target));
}

const char* Intern::CreateFile::what() const throw ()
{
	return ("Trowing error : could not create the file");
}
