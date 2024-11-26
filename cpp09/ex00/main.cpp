/*
This program must use a database in csv format which will represent bitcoin price
over time. This database is provided with this subject.
The program will take as input a second database, storing the different prices/dates
to evaluate.


*/



#include <iostream>
#include "includes/BitcoinExchange.hpp"

int	main(int argc, char* argv[])
{
	if (argc != 2) {
		std::cerr << "Error: could not open file" << std::endl;
		return (EXIT_FAILURE);
	}
	try {
		BitcoinExchange btc(argv[1]);
	}
	catch(const std::exception& e) {
			std::cerr << e.what() << std::endl;
	}
	return 0;
}
