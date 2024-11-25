#include "../includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << "\033[33m" << "Default constructor called" << "\033[0m" << std::endl;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "\033[32m" << "Destructor called" << "\033[0m" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	std::cout << "\033[34m" << "Copy constructor called" << "\033[0m" << std::endl;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	std::cout << "\033[35m" << "Copy assignment operator called" << "\033[0m" << std::endl;
	return *this;
}


