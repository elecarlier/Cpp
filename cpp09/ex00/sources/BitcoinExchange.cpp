#include "../includes/BitcoinExchange.hpp"




BitcoinExchange::BitcoinExchange(std::string path)
{
	parseDatebase();
	readInputFile(path);
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



/*Year-Month-Day*/
bool BitcoinExchange::isValidDate(const std::string& date)
{
	int year, month, day;
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	for (size_t i = 0; i < date.size(); ++i)
	{
		if ((i == 4 || i == 7) && date[i] == '-')
			continue;
		if (!isdigit(date[i])) return false;
	}


	std::istringstream(date.substr(0, 4)) >> year;
	std::istringstream (date.substr(5, 2)) >> month;
	std::istringstream (date.substr(8, 2)) >> day;



	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;


	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;

	if (month == 2) {
		bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		if (day > (isLeapYear ? 29 : 28))
		return false;
	}

	return true;
}


void BitcoinExchange::readInputFile(std::string path)
{
	std::ifstream file(path.c_str());
	std::string date;
	double value;

	if (!file.is_open())
		std::cerr << "Error: could not open file" << std::endl;


	std::string line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		if (line.empty())
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::stringstream ss(line);
		std::getline(ss, date, '|');

		try
		{
			if (isValidDate(date))
					throw InvalidDate();
			if (!(ss >> value))
				throw InvalidValue();
			if (value < 0)
				throw ValueNegativeException();
			if (value > 1000)
				throw ValueTooBig();
			calculateRes(value, date);
			//std::cout << "Valid date and value : " << date << " -> " << value << std::endl;
		}catch(const std::exception& e)
		{
			std::cerr << CYAN << "Error: Invalid value or date for date: " << date << " with value : " << value << RESET << std::endl;
		}


	}


//     #ifdef DEBUG_MODE
//     for (std::map<std::string, double>::iterator it = this->_inputMap.begin(); it != this->_inputMap.end(); ++it)
//         std::cout << "Date: " << it->first << ", Exchange rate: " << it->second << std::endl;
//     #endif

	file.close();
}

void BitcoinExchange::calculateRes(double value, std::string date)
{
	double res;
	std::cout << date << " => " << value << " = ";

	std::map<std::string, double>::iterator it;
	it = this->_dataMap.find(date);

	/*if the iterator doesnt point to the end of the map it means the exact date has been found*/
	if (it != this->_dataMap.end())
	{
		 res = it->second * value;
	}
	else
	{
		std::map<std::string, double>::iterator it = _dataMap.lower_bound(date);
		if (it == this->_dataMap.begin())
			std::cout << "date to early" << std::endl;
		else
		{
			--it; //iterate to closest earlier date
			res = it->second * value;
		}
	}
	std::cout << res << std::endl;
}


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
		try
		{
			std::getline(ss, date, ',');
			if (!isValidDate(date)) {
				throw InvalidDate();
			}

			if (!(ss >> value)) {
				throw InvalidValue();
			}

			if (value < 0 || value > 1000) {
				throw InvalidValue();
			}

			this->_dataMap[date] = value;

		}
		catch(const std::exception& e)
		{
			//std::cerr << BLUE << "DATABASE : Invalid value or date for date: " << date << " with value : " << value << RESET<< std::endl;
		}

	}

	// #ifdef DEBUG_MODE
	// 	for (std::map<std::string, double>::iterator it = this->_dataMap.begin(); it != this->_dataMap.end(); ++it)
	// 		std::cout << "Date: " << it->first << ", Value: " << it->second << std::endl;
	// #endif

	file.close();
}



const char* BitcoinExchange::InvalidDate::what() const throw()
{
	return ("Throwing exception : Invalid date :");
}

const char* BitcoinExchange::InvalidValue::what() const throw()
{
	return ("Throwing exception : Invalid value :");
}

const char*	BitcoinExchange::OpenFileException::what() const throw()
{
	return ("Throwing exception : no span found.");
}
const char*	BitcoinExchange::ValueNegativeException::what() const throw()
{
	return "Error: not a positive number";
}

const char*	BitcoinExchange::ValueTooBig::what() const throw()
{
	return "Error: too large a number";
}
