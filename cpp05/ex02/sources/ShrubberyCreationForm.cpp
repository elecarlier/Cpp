/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:46:35 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/17 19:39:34 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default Shrubbery Form", 145, 137), _target("Default Target")
{
	std::cout << "\033[33m" << "Shrubbery Default constructor called" << "\033[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Form", 145, 137), _target(target)
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

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);

	std::ofstream outfile((this->getTarget()).c_str());

	if (outfile.is_open() == false)
		std::cerr << "Unable to open " << this->getTarget() << std::endl;
	else
	{
		outfile << "       _-_" << std::endl;
    	outfile << "    /~~   ~~\\" << std::endl;
    	outfile << " /~~         ~~\\" << std::endl;
   		outfile << "{               }" << std::endl;
    	outfile << " \\  _-     -_  /" << std::endl;
    	outfile << "   ~  \\ //  ~" << std::endl;
    	outfile.close();
	}

}

std::string ShrubberyCreationForm::getTarget() const
{
	std::string name = _target + "_shrubbery";
	return (name);
}

std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm const &i)
{
	o << i.getName() << std::endl
	<< ", target : " << i.getTarget() << std::endl
	<< ", grade required to sign : " << i.getSGrade() << std::endl
	<< ", grade required to execute : " << i.getEGrade() << std::endl
	<< ", signed status : " << (i.getSigned() ? "Signed" : "Not Signed") << std::endl;
	return (o);
}
