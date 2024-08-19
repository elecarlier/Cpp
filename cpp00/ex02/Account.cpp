/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:08:58 by ecarlier          #+#    #+#             */
/*   Updated: 2024/08/19 18:53:18 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <string>
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


Account::Account(int initial_deposit)
{
	//std::cout << "Account constructor called" << std::endl;
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbAccounts++;
	_totalAmount += initial_deposit;

	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_displayTimestamp();
	std::cout
	<< "index:" <<  _accountIndex << ";"
	<< "amount:" << _amount << ";"
	<< "created" << std::endl;

}

Account::~Account()
{
	//std::cout << "Account constructor called" << std::endl;
	_displayTimestamp();
	std::cout
	<< "index:" <<  _accountIndex << ";"
	<< "amount:" << _amount << ";"
	<< "closed" << std::endl;
}

void Account::_displayTimestamp()
{
	std::time_t now = std::time(0);
	std::tm*	localtime = std::localtime(&now);

	char buffer[25];
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", localtime);
	std::cout << buffer << ' ';
}

void	Account::makeDeposit( int deposit )
{
	int	p_amout = _amount;
	_totalNbDeposits++;
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;

	_displayTimestamp();
	std::cout
	<< "index:" << _accountIndex  << ";"
	<< "p_amount:" <<  p_amout << ";"
	<< "deposit:" << deposit << ";"
	<< "amount:" << _amount << ";"
	<< "nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	int	p_amout = _amount;
	_displayTimestamp();

	std::cout << "index:" << _accountIndex  << ";";
	std::cout << "p_amount:" <<  p_amout << ";";

	if (this->checkAmount() >= withdrawal)
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		std::cout << "withdrawal:" << withdrawal << ";";
		std::cout << "amount:" << _amount << ";";
		std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
		return (true);
	}
	else
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
}

int		Account::checkAmount( void ) const
{
	return this->_amount;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout
	<< "index:" <<  _accountIndex << ";"
	<< "amount:" << _amount << ";"
	<< "deposits:" << _nbDeposits << ";"
	<< "withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout
	<< "accounts:" <<  _nbAccounts << ";"
	<< "total:" << _totalAmount << ";"
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
