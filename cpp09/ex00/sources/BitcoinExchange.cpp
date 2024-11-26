#include "../includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string path)
{
	(void)path;
	parseDatebase();
	//parseInput(path);
	#ifdef DEBUG_MODE
		std::cout << "\033[33m" << "Default constructor called" << "\033[0m" << std::endl;
	#endif
}

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
	*this = copy;

	#ifdef DEBUG_MODE
		std::cout << "\033[34m" << "Copy constructor called" << "\033[0m" << std::endl;
	#endif
}

/*not done*/
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	(void)copy;
	#ifdef DEBUG_MODE
		std::cout << "\033[35m" << "Copy assignment operator called" << "\033[0m" << std::endl;
	#endif
	return *this;
}


// void BitcoinExchange::parseInput(std::string path)
// {

// }

void BitcoinExchange::parseDatebase()
{
	std::string date;
	double value;


	std::ifstream file("data.csv");
	if (!file.is_open())
		throw OpenFileException();

	std::string line;
	std::getline(file, line); //ignore first line
	while (std::getline(file, line))
	{
		std::stringstream ss(line);

		std::getline(ss, date, ',');
		ss >> value;
		this->_dataMap[date] = value;
	}

	#ifdef DEBUG_MODE
		for (std::map<std::string, double>::iterator it = this->_dataMap.begin(); it != this->_dataMap.end(); ++it)
			std::cout << "Date: " << it->first << ", Value: " << it->second << std::endl;
	#endif

	//file.close();
}

// void BitcoinExchange::checkDate(std::string date)
// {

// }

// void BitcoinExchange::checkValue(std::string date)
// {

// }

const char*	BitcoinExchange::OpenFileException::what() const throw()
{
	return ("Throwing execption : no span found.");
}
