/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:32:57 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/20 12:24:55 by ecarlier         ###   ########.fr       */
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

	try
	{
		Intern someRandomIntern;
		AForm *rrf;
		AForm *RRF;

		rrf = someRandomIntern.makeForm("robotomy request", "bender");
		std::cout << *rrf << std::endl;

		RRF = someRandomIntern.makeForm("ROBOTOMY REQUEST", "bender");
		std::cout << *RRF << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n'<< std::endl;
	}


	std::cout << "\033[1m" << "\n --- ShrubberyCreationForm  ---" << "\033[0m" <<std::endl<<std::endl;

	std::cout << "\033[1m" << "\n --- PresidentialPardonForm  ---" << "\033[0m" <<std::endl<<std::endl;

	return (0);
}
