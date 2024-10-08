/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:24:51 by ecarlier          #+#    #+#             */
/*   Updated: 2024/08/22 13:35:18 by ecarlier         ###   ########.fr       */
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
	std::cout << "DEBUG : I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
	std::cout << "INFO : I cannot believe adding extra bacon costs more money. You didn t  put enough bacon in my burger! If you did, I would t be asking for more!" << std::endl;
}


void Harl::warning( void )
{
	std::cout << "WARNING : I think I deserve to have some extra bacon for free. I ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void )
{
	std::cout << "ERROR : This is unacceptable! I want to speak to the manager now." << std::endl;
}


void Harl::complain( std::string level )
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*funcPtr[4])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*funcPtr[i])();
		}
	}
}
