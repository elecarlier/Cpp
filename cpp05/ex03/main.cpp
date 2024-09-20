/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:32:57 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/20 13:11:57 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Bureaucrat.hpp"
#include "includes/AForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/Intern.hpp"


int main()
{
	std::cout << "\033[1m" << "\n --- RobotomyRequestForm  ---" << "\033[0m" <<std::endl<<std::endl;

	Bureaucrat Bob("Bob", 1);
	Intern someRandomIntern;

	try
	{

		AForm *rrf;
		AForm *RRF;

		rrf = someRandomIntern.makeForm("robotomy request", "bender");
		std::cout << *rrf << std::endl;

		RRF = someRandomIntern.makeForm("ROBOTOMY REQUEST", "bender");
		std::cout << *RRF << std::endl;

		Bob.signForm(*rrf);
		delete rrf;
		delete RRF;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n'<< std::endl;
	}


	std::cout << "\033[1m" << "\n --- ShrubberyCreationForm  ---" << "\033[0m" <<std::endl<<std::endl;
	try
	{
		AForm *scf;

		scf = someRandomIntern.makeForm("Shrubbery Creation", "bender");
		std::cout << *scf << std::endl;
		delete scf;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n'<< std::endl;
	}

	std::cout << "\033[1m" << "\n --- PresidentialPardonForm  ---" << "\033[0m" <<std::endl<<std::endl;

	try
	{
		AForm *ppf;

		ppf = someRandomIntern.makeForm("Presidential Pardon", "bender");
		std::cout << *ppf << std::endl;

		delete ppf;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n'<< std::endl;
	}

	std::cout << "\033[1m" << "\n --- Invalid name  ---" << "\033[0m" <<std::endl<<std::endl;

	try
	{
		AForm *ppf;

		ppf = someRandomIntern.makeForm("invalid form", "bender");
		std::cout << *ppf << std::endl;
		delete ppf;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n'<< std::endl;
	}

	return (0);
}
