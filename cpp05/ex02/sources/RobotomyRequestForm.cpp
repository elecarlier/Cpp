/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:43:43 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/17 19:57:45 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Default Robotomy Form", 72, 45), _target("Default Target")
{
	std::cout << "\033[33m" << "Robotomy Default constructor called" << "\033[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Default Robotomy Form", 72, 45), _target(target)
{
	std::cout << "\033[33m" << "Robotomy constructor called" << "\033[0m" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "\033[32m" << "Robotomy Destructor called" << "\033[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
{
	std::cout << "\033[34m" << "Robotomy Copy constructor called" << "\033[0m" << std::endl;
	*this = copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	std::cout << "\033[35m" << "Robotomy Copy assignment operator called" << "\033[0m" << std::endl;
	if (this != &copy)
	{
		this->_target = copy._target;
	}
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	std::cout << "Making some drilling noises....\n" ;

	std::srand(std::time(NULL));
	int success = std::rand() % 2;
	if (success)
		std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->getTarget() << " has not been robotomized successfully" << std::endl;

}

std::string RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm const &i)
{
	o << i.getName() << std::endl
	<< ", grade required to sign : " << i.getSGrade() << std::endl
	<< ", grade required to execute : " << i.getEGrade() << std::endl
	<< ", signed status : " << (i.getSigned() ? "Signed" : "Not Signed") << std::endl;
	return (o);
}
