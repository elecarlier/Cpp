/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:52:57 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/17 17:27:00 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Default Robotomy Form", 25, 5), _target("Default Target")
{
	std::cout << "\033[33m" << "Presidential Default constructor called" << "\033[0m" << std::endl;

}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Default Robotomy Form", 25, 5), _target(target)
{
	std::cout << "\033[33m" << "Presidential constructor called" << "\033[0m" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "\033[32m" << "Presidential Destructor called" << "\033[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
{
	std::cout << "\033[34m" << "Presidential Copy constructor called" << "\033[0m" << std::endl;
	*this = copy;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	std::cout << "\033[35m" << "Presidential Copy assignment operator called" << "\033[0m" << std::endl;
	if (this != &copy)
	{
		this->_target = copy._target;
	}
	return *this;
}


std::string PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}
