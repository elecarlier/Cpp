/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:32:57 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/17 20:00:24 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Bureaucrat.hpp"
#include "includes/AForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/PresidentialPardonForm.hpp"

int	main (void)
{
	std::cout << "\033[1m" << "\n ---  ShrubberyCreationForm ---" << "\033[0m" <<std::endl;
	std::cout << "\033[1m" << "\n --- Test 0 : Constructors ---" << "\033[0m" <<std::endl<<std::endl;

	try
	{
		ShrubberyCreationForm form("shrubb");
		std::cout << form << std::endl;
		ShrubberyCreationForm defaul;
		std::cout << defaul << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n'<< std::endl;
	}

	std::cout << std::endl;
	std::cout << "\033[1m" << " --- Test 1 :  signing grade too low ---" << "\033[0m" <<std::endl<<std::endl;

	try
	{
		ShrubberyCreationForm form("shrubb");
		// std::cout << form << std::endl;
		Bureaucrat	John("John", 150);

		std::cout << std::endl;
		John.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n'<< std::endl;
	}

	std::cout << std::endl;
	std::cout << "\033[1m" << " --- Test 2 : exec file not signed---" << "\033[0m" <<std::endl<<std::endl;

	try
	{
		ShrubberyCreationForm form("shrubb");
		// std::cout << form << std::endl;
		Bureaucrat	John("John", 150);

		std::cout << std::endl;
		John.executeForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n'<< std::endl;
	}
	std::cout << std::endl;
	std::cout << "\033[1m" << " --- Test 3 ---" << "\033[0m" <<std::endl<<std::endl;

	try
	{
		ShrubberyCreationForm form("shrubb");
		// std::cout << form << std::endl;
		Bureaucrat	John("John", 150);
		Bureaucrat	Pierre("Pierre", 1);

		std::cout << std::endl;
		Pierre.signForm(form);
		John.executeForm(form);
		Pierre.executeForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n'<< std::endl;
	}


	std::cout << "\033[1m" << "\n ---  RobotomyRequestForm ---" << "\033[0m" <<std::endl;
	// std::cout << "\033[1m" << "\n --- Test 0 : Constructors ---" << "\033[0m" <<std::endl<<std::endl;

	// try
	// {
	// 	RobotomyRequestForm form("form");
	// 	std::cout << form << std::endl;
	// 	RobotomyRequestForm defaul;
	// 	std::cout << defaul << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n'<< std::endl;
	// }

	// std::cout << std::endl;
	// std::cout << "\033[1m" << " --- Test 1 :  signing grade too low ---" << "\033[0m" <<std::endl<<std::endl;

	// try
	// {
	// 	RobotomyRequestForm form("form");
	// 	// std::cout << form << std::endl;
	// 	Bureaucrat	John("John", 150);

	// 	std::cout << std::endl;
	// 	John.signForm(form);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n'<< std::endl;
	// }

	// std::cout << std::endl;
	// std::cout << "\033[1m" << " --- Test 2 : exec file not signed---" << "\033[0m" <<std::endl<<std::endl;

	// try
	// {
	// 	RobotomyRequestForm form("form");
	// 	// std::cout << form << std::endl;
	// 	Bureaucrat	John("John", 150);

	// 	std::cout << std::endl;
	// 	John.executeForm(form);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n'<< std::endl;
	// }
	std::cout << std::endl;
	std::cout << "\033[1m" << " --- Test 3 ---" << "\033[0m" <<std::endl<<std::endl;

	try
	{
		RobotomyRequestForm form("form");
		// std::cout << form << std::endl;
		Bureaucrat	John("John", 150);
		Bureaucrat	Pierre("Pierre", 1);

		std::cout << std::endl;
		Pierre.signForm(form);
		Pierre.signForm(form);
		John.executeForm(form);
		Pierre.executeForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n'<< std::endl;
	}


	std::cout << "\033[1m" << "\n ---  PresidentialPardonForm ---" << "\033[0m" <<std::endl;
	// std::cout << "\033[1m" << "\n --- Test 0 : Constructors ---" << "\033[0m" <<std::endl<<std::endl;

	// try
	// {
	// 	PresidentialPardonForm form("form");
	// 	std::cout << form << std::endl;
	// 	PresidentialPardonForm defaul;
	// 	std::cout << defaul << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n'<< std::endl;
	// }

	// std::cout << std::endl;
	// std::cout << "\033[1m" << " --- Test 1 :  signing grade too low ---" << "\033[0m" <<std::endl<<std::endl;

	// try
	// {
	// 	PresidentialPardonForm form("form");
	// 	// std::cout << form << std::endl;
	// 	Bureaucrat	John("John", 150);

	// 	std::cout << std::endl;
	// 	John.signForm(form);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n'<< std::endl;
	// }

	// std::cout << std::endl;
	// std::cout << "\033[1m" << " --- Test 2 : exec file not signed---" << "\033[0m" <<std::endl<<std::endl;

	// try
	// {
	// 	PresidentialPardonForm form("form");
	// 	// std::cout << form << std::endl;
	// 	Bureaucrat	John("John", 150);

	// 	std::cout << std::endl;
	// 	John.executeForm(form);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n'<< std::endl;
	// }
	std::cout << std::endl;
	std::cout << "\033[1m" << " --- Test 3 ---" << "\033[0m" <<std::endl<<std::endl;

	try
	{
		PresidentialPardonForm form("form");
		// std::cout << form << std::endl;
		Bureaucrat	John("John", 150);
		Bureaucrat	Pierre("Pierre", 1);

		std::cout << std::endl;
		Pierre.signForm(form);
		Pierre.signForm(form);
		John.executeForm(form);
		Pierre.executeForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n'<< std::endl;
	}


	return (0);
}
