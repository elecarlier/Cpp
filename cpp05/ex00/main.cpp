/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:32:57 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/16 18:35:25 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Bureaucrat.hpp"

int	main (void)
{
	std::cout << "\033[1m" << " --- Test 0 : default constructor ---" << "\033[0m" <<std::endl<<std::endl;

	try
	{
			Bureaucrat defaul;
			std::cout << defaul;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n'<< std::endl;
	}

	std::cout << "\033[1m" << " --- Test 1 : Bureaucrat parametrized constructor  ---" << "\033[0m" <<std::endl<<std::endl;

	try
	{
		Bureaucrat Whitfield("Whitfield", 60);
		std::cout << Whitfield;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n'<< std::endl;
	}

	std::cout << "\033[1m" << " --- Test 2 : Bureaucrat parametrized constructor too low ---" << "\033[0m" <<std::endl<<std::endl;

	try
	{
		Bureaucrat Pompington("Pompington", 460);
		std::cout << Pompington;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n'<< std::endl;
	}

	std::cout << "\033[1m" << " --- Test 3 : Bureaucrat parametrized constructor too high ---" << "\033[0m" <<std::endl<<std::endl;

	try
	{
		Bureaucrat Pompington("Pompington", 0);
		std::cout << Pompington;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n' << std::endl;
	}


	std::cout  << "\033[1m" << " --- Test 4 : incrementGrade() ---" << "\033[0m" <<std::endl <<std::endl;

	try
	{
		Bureaucrat Pompington("Pompington", 42);
		std::cout << Pompington;
		for (int i = 0; i < 41; i++)
			Pompington.incrementGrade();
		std::cout << Pompington;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n' << std::endl;
	}

	std::cout  << "\033[1m" << " --- Test 5 : incrementGrade() too high---" << "\033[0m" <<std::endl <<std::endl;

	try
	{
		Bureaucrat Pompington("Pompington", 42);
		std::cout << Pompington;
		for (int i = 0; i < 42; i++)
			Pompington.incrementGrade();
		std::cout << Pompington;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n' << std::endl;
	}

	std::cout  << "\033[1m" << " --- Test 6 : decrementGrade() ---" << "\033[0m" <<std::endl <<std::endl;

	try
	{
		Bureaucrat Pompington("Pompington", 42);
		std::cout << Pompington;
		for (int i = 0; i < 41; i++)
			Pompington.decrementGrade();
		std::cout << Pompington;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n' << std::endl;
	}

	std::cout << "\033[1m" << " --- Test 7 : decrementGrade() too low---" << "\033[0m" <<std::endl <<std::endl;

	try
	{
		Bureaucrat Pompington("Pompington", 130);
		std::cout << Pompington;
		for (int i = 0; i < 42; i++)
			Pompington.decrementGrade();
		std::cout << Pompington;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n' << std::endl;
	}

	return (0);
}
