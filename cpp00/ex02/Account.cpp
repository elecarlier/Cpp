/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:08:58 by ecarlier          #+#    #+#             */
/*   Updated: 2024/08/19 17:17:52 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <string>
#include <iostream>
#include <ctime>
#include <iomanip>

Account::Account(int initial_deposit)
{
	//std::cout << "Account constructor called" << std::endl;

	_amount = initial_deposit;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_accountIndex = _nbAccounts;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_displayTimestamp();
	std::cout
	<< "index: " <<  _nbAccounts << ";"
	<< "amount:" << _totalAmount << ";"
	<< "created";

}

Account::~Account()
{
	//std::cout << "Account constructor called" << std::endl;
}

void Account::_displayTimestamp()
{
	std::time_t now = std::time(nullptr);
	std::tm*	localtime = std::localtime(&now);

	char buffer[25];
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", localtime);
	std::cout << buffer << ' ';
}

void	Account::makeDeposit( int deposit )
{
	
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout
	<< "index:" <<  _nbAccounts << ";"
	<< "amount:" << _totalAmount << ";"
	<< "deposits:" << _totalNbDeposits << ";"
	<< "withdrawals:" << _totalNbWithdrawals << std::endl;
}





int	Account::getNbAccounts()
{
	return _nbAccounts;
}

int	Account::getTotalAmount()
{
	return _totalAmount;
}

int	Account::getNbDeposits()
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals()
{
	return _totalNbWithdrawals;
}
