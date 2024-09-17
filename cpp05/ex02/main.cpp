/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:32:57 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/16 20:09:25 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Bureaucrat.hpp"

int	main (void)
{
	std::cout << "\033[1m" << "\n --- Test 0 : default constructor ---" << "\033[0m" <<std::endl<<std::endl;

	try
	{
		Form form;
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n'<< std::endl;
	}

	std::cout << "\033[1m" << " --- Test 1 : signing grade too low ---" << "\033[0m" <<std::endl<<std::endl;

	try
	{
		Form form("Murder on the Orient Express", 450, 40);
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n'<< std::endl;
	}

	std::cout << "\033[1m" << " --- Test 2 : executing grade too low ---" << "\033[0m" <<std::endl<<std::endl;

	try
	{
		Form form("Murder on the Orient Express", 30, 450);
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n'<< std::endl;
	}

	std::cout << "\033[1m" << " --- Test 3 : signing too high & executing grade too low ---" << "\033[0m" <<std::endl<<std::endl;

	try
	{
		Form form("Murder on the Orient Express", 0, 450);
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n'<< std::endl;
	}

	std::cout << "\033[1m" << " --- Test 4 : Bureaucrat should be able to sign ---" << "\033[0m" <<std::endl<<std::endl;

	try
	{
		Bureaucrat Agatha("Agatha", 42);
		std::cout << Agatha << std::endl;
		Form form("Murder on the Orient Express", 50, 40);
		std::cout << form << std::endl;
		Agatha.signForm(form);
		std::cout << std::endl;
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n'<< std::endl;
	}

	std::cout << "\033[1m" << " --- Test 5 : Bureaucrat should NOT be able to sign TWICE ---" << "\033[0m" <<std::endl<<std::endl;

	try
	{
		Bureaucrat Agatha("Agatha", 20);
		//std::cout << Agatha << std::endl;
		Form form("Murder on the Orient Express", 50, 40);
		//std::cout << form << std::endl;
		Agatha.signForm(form);
		//std::cout << std::endl;
		//std::cout << form << std::endl;
		Agatha.signForm(form);
		std::cout << std::endl;
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n'<< std::endl;
	}

	std::cout << "\033[1m" << " --- Test 6 : Bureaucrat should NOT be able to sign garde TOO LOW ---" << "\033[0m" <<std::endl<<std::endl;

	try
	{
		Bureaucrat Agatha("Agatha", 60);
		std::cout << Agatha << std::endl;
		Form form("Murder on the Orient Express", 50, 40);
		// std::cout << form << std::endl;
		Agatha.signForm(form);
		std::cout << std::endl;
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n'<< std::endl;
	}

	return (0);
}
