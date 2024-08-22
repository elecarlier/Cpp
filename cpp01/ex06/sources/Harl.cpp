/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:24:51 by ecarlier          #+#    #+#             */
/*   Updated: 2024/08/22 14:51:49 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"


Harl::Harl()
{
	std::cout << "\033[33m" <<"Harl constructor called" << "\033[0m" <<  std::endl;
}

Harl::~Harl()
{

	std::cout << "\033[32m" << "Harl desconstructor called" << "\033[0m"  << std::endl;
}


void Harl::debug( void )
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn t  put enough bacon in my burger! If you did, I would t be asking for more!" << std::endl;
}


void Harl::warning( void )
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void )
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}


void Harl::complain( std::string level )
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*funcPtr[4])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

	int loglevel;
	loglevel = 5;

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			loglevel = i + 1;
		}
	}
	switch (loglevel)
	{
		case 1:
			(this->*funcPtr[0])();
		case 2:
			(this->*funcPtr[1])();
		case 3:
			(this->*funcPtr[2])();
		case 4:
			(this->*funcPtr[3])();
		case 5:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
