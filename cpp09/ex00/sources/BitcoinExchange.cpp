#include "../includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	#ifdef DEBUG_MODE
		std::cout << "\033[33m" << "Default constructor called" << "\033[0m" << std::endl;
	#endif
}

BitcoinExchange::~BitcoinExchange()
{
	#ifdef DEBUG_MODE
		std::cout << "\033[32m" << "Destructor called" << "\033[0m" << std::endl;
	#endif
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	#ifdef DEBUG_MODE
		std::cout << "\033[34m" << "Copy constructor called" << "\033[0m" << std::endl;
	#endif
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	#ifdef DEBUG_MODE
		std::cout << "\033[35m" << "Copy assignment operator called" << "\033[0m" << std::endl;
	#endif
	return *this;
}


void BitcoinExchange::checkDate(std::string date)
{

}

void BitcoinExchange::checkValue(std::string date)
{

}
